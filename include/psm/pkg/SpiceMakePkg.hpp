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
    uint8_t* offset_;
    size_t length_;
    string version_;
public:
    SpiceMakePkgModule(uint8_t* offset, size_t length);
    [[nodiscard]] bool checksum(uint32_t crc) const;
};

class SpiceMakePkg {
    unordered_map<string, SpiceMakePkgModule> modules_;
    vector<uint8_t> data_;
    string metadata_;
public:
    SpiceMakePkg(vector<uint8_t> data);
};
