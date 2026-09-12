# SPICE Make Project File (Source)

> **Last Edit: 2026-09-12**

## Overview

This document is the definition for source directory of the Spice Make Project

## Structure

The Spice Make Project has the following structure.

```text
src/
├── main.spm
├── other.spm
├── sub
│  ├── sub1.spm
│  └── ...
└── ...
```

### `xxx.spm`

This is the source file for Spice Make
that it was a super set of Spice.

Other commands are defined as [follows](#command-of-spice-make).

## Command of Spice Make

### `#include <aaa:mmm@vvv>`

Import modules whose **author** is `aaa`
and the **name** is `mmm`
and the **version** is `vvv`.
These modules must be introduced in `link_include_local` or `link_include_remote` at `project.smake`.

This command will be unzipped to `./aaa-mmm-vvv` when Spice Make is compiled.

### `#include <nnn> form <aaa:mmm@vvv>`

Similar to the previous one,
but command will be unzipped to `./nnn` instead of `./aaa-mmm-vvv`.

---

**Copyright (c) 2026 Phiarc Teams.**  
**This document adopts the [Creative Commons Attribution-ShareAlike 4.0 Unported](https://creativecommons.org/licenses/by-sa/4.0/).**
