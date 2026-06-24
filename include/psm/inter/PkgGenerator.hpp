// =====================================================================
// Copyright (c) 2026 Phiarc Team
// Licensed under the GNU General Public License Version 3.0 or later
// https://github.com/phi-amateur-radio-community/spice-make
// =====================================================================
// Path /include/psm/inter/PkgGenerator.hpp
// Interface of SpiceMakePkg class generator.

#pragma once

#include <psm/pkg/SpiceMakePkg.hpp>

class PkgGenerator {
public:
    virtual ~PkgGenerator() = default;
    virtual SpiceMakePkg getSpiceMakePkg();
    virtual uint32_t loadSpiceMakePkgModule(SpiceMakePkgModule module);
    virtual uint32_t loadSpiceMakePkgModuleVersion(SpiceMakePkgModule module);
};
