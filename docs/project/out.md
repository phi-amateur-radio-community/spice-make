# SPICE Make Project File

> **Last Edit: 2026-09-12**

## Overview

This document is the definition for Spice Make Project

## Structure

The Spice Make Project has the following structure.

```text
out/
├── deps/
│  ├── deps1/
│  │  ├── v1_0_0/
│  │  │  ├── deps1-v1_0_0-module1/
│  │  │  │  ├── file1
│  │  │  │  └── ...
│  │  │  └── ...
│  │  └── ...
│  └── ...
├── src/
│  ├── main.spmo
│  ├── other.spmo
│  ├── sub
│  │  ├── sub1.spmo
│  │  └── ...
│  └ ...
├── remote/
│  ├── remote1.lists
│  └── ...
├── download/
│  ├ remote-deps1.zst.tar
│  └ ...
└── unzip/
   ├── remote1
   │  ├── remote-deps1/
   │  │  ├── file1
   │  │  └── ...
   │  └── ...
   └── ...
```

### `deps`

This directory is used to store the SPICE source code of dependence.

### `src`

This directory is used to store the SPICE source code of project.
That is the compiling products of [Spice Make Source File](/docs/project/source.md).

### `remote`

This directory is used to store the module lists from all remote repositories.

### `download`

This directory is used to store the downloaded module file from remote repositories.

### `unzip`

This directory is used to store the unzipped file from the downloaded module file.

---

**Copyright (c) 2026 Phiarc Teams.**  
**This document adopts the [Creative Commons Attribution-ShareAlike 4.0 Unported](https://creativecommons.org/licenses/by-sa/4.0/).**
