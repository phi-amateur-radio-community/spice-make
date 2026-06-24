// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /include/psm/util/Reader.hpp
// Header file of reader tools.

#pragma once

#include <concepts>
#include <cstdint>
#include <string_view>
#include <vector>
#include <bits/locale_facets_nonio.h>

using namespace std;

template<integral T>
bool readHex(string_view str, T& value);

void readBits(ifstream& ifs, vector<uint8_t>& data);
