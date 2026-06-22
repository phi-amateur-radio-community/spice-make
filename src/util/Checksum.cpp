// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /src/util/Checksum.cpp
// Checksum calculator

#include <psm/util/Checksum.hpp>

uint32_t crc32(const uint8_t* data, const size_t length) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; i++) {
        crc = crc ^ CRC32_TABLE[data[i]];
    }
    return crc;
}
