// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /src/util/Reader.cpp
// Reader tools.

#include <psm/util/Reader.hpp>
#include <charconv>
#include <fstream>

template<integral T>
bool readHex(string_view str, T &value) {
    auto [ptr, ec] = from_chars(
        str.data(), str.data() + str.size(),
        value,
        16);
    return ptr == str.data() + str.size() && ec == 0;
}

void readBits(ifstream& ifs, vector<uint8_t>& data) {
    ifs.read(reinterpret_cast<char*>(data.data()), static_cast<streamsize>(data.size()));
}
