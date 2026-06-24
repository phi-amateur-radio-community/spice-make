// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /src/pkg/SpiceMakePkg.cpp
// SpiceMake library file handler.

#include <psm/pkg/SpiceMakePkg.hpp>
#include <psm/util/Checksum.hpp>
#include <utility>

SpiceMakePkgModule::SpiceMakePkgModule(const streamsize offset, const size_t length) : offset_(offset), length_(length) {}

bool SpiceMakePkgModule::checksum(const uint32_t crc) const {
    return crc32(data_.data(), length_) == crc;
}

streamsize SpiceMakePkgModule::getOffset() const {
    return offset_;
}

size_t SpiceMakePkgModule::getLength() const {
    return length_;
}

void SpiceMakePkgModule::loadVersion(string version) {
    is_version_loaded_ = true;
    version_ = std::move(version);
}

vector<uint8_t>& SpiceMakePkgModule::loadData() {
    is_data_loaded_ = true;
    return data_;
}
