# SPICE Make Project File

> **Last Edit: 2026-09-12**

## Overview

This document is the definition for Spice Make Project

## Structure

The Spice Make Project has the following structure.

```text
./
├── project.smake
├── src/
│  ├── main.spm
│  ├── other.spm
│  ├── sub
│  │  ├── sub1.spm
│  │  └── ...
│  └── ...
├── out/
│  ├── deps/
│  │  ├── deps1/
│  │  │  ├── v1_0_0/
│  │  │  │  ├── deps1-v1_0_0-module1/
│  │  │  │  │  ├── file1
│  │  │  │  │  └── ...
│  │  │  │  └── ...
│  │  │  └── ...
│  │  └── ...
│  ├── src/
│  │  ├── main.spmo
│  │  ├── other.spmo
│  │  ├── sub
│  │  │  ├── sub1.spmo
│  │  │  └── ...
│  │  └ ...
│  ├── remote/
│  │  ├── remote1.lists
│  │  └── ...
│  ├── download/
│  │  ├ remote-deps1.zst.tar
│  │  └ ...
│  └── unzip/
│     ├── remote1
│     │  ├── remote-deps1.spmo
│     │  └── ...
│     └── ...
└── ...
```

### `project.smake`

```text
smake([Spice Make Version])

project([Project Name] [Project Version])

add_simulate([Simulate Name] [Main File Path])

add_library([Library Name])

add_module([Module 1 Name] [Version] [File Path])
expend_library([Library Name] [Module 1 Name])

add_module([Module 2 Name] [Version] [File Path])
expend_library([Library Name] [Module 2 Name])

link_include_local([Library Path])

add_remote([Repository Name] [Repository URL])
link_include_remote([Author] [Module] [Version])
```

This file is used to descript the structure of the Spice Make Project.

For details, please refer to [command](/docs/project/command/list.md).

### `src`

This directory is used to store the source code of the Spice Make.

For details, please refer to [source](/docs/project/source.md).

### `out`

This directory is used to store the compiled products of the Spice Make.

For details, please refer to [out](/docs/project/out.md).

---

**Copyright (c) 2026 Phiarc Teams.**  
**This document adopts the [Creative Commons Attribution-ShareAlike 4.0 Unported](https://creativecommons.org/licenses/by-sa/4.0/).**
