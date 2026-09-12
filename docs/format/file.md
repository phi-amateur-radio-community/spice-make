# SPICE Make Package File Format

> **Last Edit: 2026-06-21**

## Overview

This document describes the syntax and semantics of the SPICE Package file format.

## Structure

```text
[File Header]
[Index List]
[Data List]
```

### File Header

```text
[Index List Offset]<SP>[Index List Length]<\n>
[Information]<\n>
```

> **Note** Only ASCII characters are allowed in this section.

- **Index List Offset:** Records the starting offset of the [Index List](#index-list).
- **Index List Length:** Records the length (in bytes) of the [Index List](#index-list).
- **Information:** Metadata for the library file, such as author, copyright and packaging timestamp, etc.

### Index List

```text
[Module Name 1]:[Module Index 1]<\n>
[Module Name 2]:[Module Index 2]<\n>
......
[Module Name N]:[Module Index N]<\n>
```

- **Module Name N:** Name of the module. (Must consist only of lowercase letters `a-z` and `-`)
- **Module Index N:** Relative offset from the [Index List Pointer](#file-header). (Must be a hexadecimal value, and one or more hexadecimal digits)

### Data List

```text
[Module 1 Checksum]<SP>[Module 1 Version]<SP>[Module 1 Data]
[Module 2 Checksum]<SP>[Module 2 Version]<SP>[Module 2 Data]
......
[Module N Checksum]<SP>[Module N Version]<SP>[Module N Data]
```

> **Note** No newline characters `\n` are allowed.

- **Module N Checksum:** `CRC32` checksum of the module data. (Must be a hexadecimal value, and one or more hexadecimal digits)
- **Module N Version:** The version of the module, such as `1.0.1`. (Must consist only of number `0-9` and `.`)
- **Module N Data:** The zstd-compressed module data.

---

**Copyright (c) 2026 Phiarc Teams.**  
**This document adopts the [Creative Commons Attribution-ShareAlike 4.0 Unported](https://creativecommons.org/licenses/by-sa/4.0/).**
