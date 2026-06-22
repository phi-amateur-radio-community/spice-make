// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /include/psm/util/Checksum.hpp
// Header file of checksum calculator.

#pragma once

#include <array>
#include <cstdint>

using namespace std;

consteval uint32_t crc32_entry(const uint32_t data) {
    uint32_t c = data;
    for (int i = 0; i < 8; i++) {
        c = (c & 1) ? (c >> 1) ^ 0xEDB88320 : c >> 1;
    }
    return ~c;
}

consteval auto make_crc32_table() {
    array<uint32_t, 256> crc32_table{};
    for (uint32_t i = 0; i < 256; i++) {
        crc32_table[i] = crc32_entry(i);
    }
    return crc32_table;
}

constexpr auto CRC32_TABLE = make_crc32_table();

uint32_t crc32(const uint8_t* data, size_t length);
