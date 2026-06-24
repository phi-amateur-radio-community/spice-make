// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /src/io/PkgFile.cpp
// SPICE library file class.

#include <psm/io/PkgFile.hpp>
#include <charconv>
#include <sstream>
#include <psm/util/Reader.hpp>

SpiceMakePkgFile::SpiceMakePkgFile(const string& file_name) {
    file_ = ifstream(file_name, ios::in | ios::binary);
}

SpiceMakePkg SpiceMakePkgFile::getSpiceMakePkg() {
    string line;
    getline(file_, line);
    metadata_offset_ = file_.tellg();
    streamsize map_offset;
    streamsize map_length;
    stringstream line_ss(line);
    line_ss >> map_offset >> map_length;
    metadata_length_ = map_offset;
    file_.seekg(map_offset);
    string index_map(map_length, '\0');
    file_.read(index_map.data(), map_length);
    size_t begin = 0;
    unordered_map<string, SpiceMakePkgModule> modules;
    while (begin < map_length) {
        size_t end = index_map.find('\n', begin);
        if (end == string::npos) {
            end = map_length;
        }
        string_view module_index_entry(index_map.data() + begin, end - begin);
        const size_t pos = module_index_entry.find(':');
        string_view module_name = module_index_entry.substr(0, pos);
        string_view module_offset_str = module_index_entry.substr(pos + 1);
        streamsize module_offset;

        if (!readHex(module_offset_str, module_offset)) {
            throw runtime_error("Failed to parse module offset.");
        }

        SpiceMakePkgModule module(module_offset, end - begin);

        modules.emplace(module_name, module);
        begin = end;
    }
    return SpiceMakePkg(modules);
}

bool SpiceMakePkgFile::loadSpiceMakePkgModule(SpiceMakePkgModule module) {
    const uint32_t module_checksum = loadSpiceMakePkgModuleVersion(module);
    auto data = module.loadData();
    data.resize(module.getLength());
    readBits(file_, data);
    return module.checksum(module_checksum);
}

uint32_t SpiceMakePkgFile::loadSpiceMakePkgModuleVersion(SpiceMakePkgModule module) {
    file_.seekg(module.getOffset());
    string module_checksum_str;
    string module_version;
    file_ >> module_checksum_str >> module_version;
    module.loadVersion(module_version);
    uint32_t module_checksum;

    if (!readHex(module_checksum_str, module_checksum)) {
        throw runtime_error("Failed to parse module checksum.");
    }

    return module_checksum;
}

string SpiceMakePkgFile::getInformation() {
    file_.seekg(metadata_offset_);
    string information(metadata_length_, '\0');
    file_.read(information.data(), metadata_length_);
    return information;
}
