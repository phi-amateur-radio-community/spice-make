// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /include/psm/pkg/SpiceMakePkg.hpp
// Header file of SpiceMake library file handler.

#pragma once

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class SpiceMakePkgModule {
    const streamsize offset_;
    const size_t length_;
    string version_{};
    vector<uint8_t> data_;
    bool is_version_loaded_{false};
    bool is_data_loaded_{false};
public:
    SpiceMakePkgModule(streamsize offset, size_t length);
    [[nodiscard]] streamsize getOffset() const;
    [[nodiscard]] size_t getLength() const;
    [[nodiscard]] bool checksum(uint32_t crc) const;
    void loadVersion(string version);
    vector<uint8_t>& loadData();
    [[nodiscard]] vector<uint8_t> decompress() const;
};

class SpiceMakePkg {
    unordered_map<string, SpiceMakePkgModule> modules_;
public:
    explicit SpiceMakePkg(unordered_map<string, SpiceMakePkgModule> modules);
    SpiceMakePkgModule getModule(const string& name);
};
