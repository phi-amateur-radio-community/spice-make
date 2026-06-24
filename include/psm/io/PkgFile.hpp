// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /include/psm/io/PkgFile.hpp
// Header file of SPICE library file class.

#pragma once

#include <fstream>
#include <psm/pkg/SpiceMakePkg.hpp>
#include <psm/inter/PkgGenerator.hpp>

using namespace std;

class SpiceMakePkgFile : public PkgGenerator {
    ifstream file_;
    streamsize metadata_offset_{};
    streamsize metadata_length_{};
public:
    explicit SpiceMakePkgFile(const string& file_name);
    string getInformation();
    SpiceMakePkg getSpiceMakePkg() override;
    bool loadSpiceMakePkgModule(SpiceMakePkgModule module) override;
    uint32_t loadSpiceMakePkgModuleVersion(SpiceMakePkgModule module) override;
};
