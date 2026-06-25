// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /src/arg/Command.cpp
// Command handler.

#include <psm/arg/Command.hpp>

#include <CLI/CLI.hpp>

int command(const int argc, char *argv[]) {
    CLI::App app{"SPICE Make"};
    app.footer(
    R"(Copyright (c) 2026 Phiarc Team
    License: GNU General Public License Version 3 or later
    https://github.com/phi-amateur-radio-community/spice-make
    )");
    CLI11_PARSE(app, argc, argv);
    return 0;
}
