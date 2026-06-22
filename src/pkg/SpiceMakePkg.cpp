// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /src/pkg/SpiceMakePkg.cpp
// SpiceMake library file handler.

#include <psm/pkg/SpiceMakePkg.hpp>
#include <psm/util/Checksum.hpp>

SpiceMakePkgModule::SpiceMakePkgModule(uint8_t *offset, const size_t length) {
    offset_ = offset;
    length_ = length;
}

bool SpiceMakePkgModule::checksum(const uint32_t crc) const {
    return crc32(offset_, length_) == crc;
}
