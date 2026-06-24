// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /src/Main.cpp
// Main of SpiceMake.

#include <CLI/CLI.hpp>

int main(const int argc, char* argv[]) {
    CLI::App app{"SPICE Make"};
    CLI11_PARSE(app, argc, argv);
    return 0;
}
