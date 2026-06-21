# SPICE Make Package File Format

> **Last Edit: 2026-06-21**

## Overview

This document describes the syntax and semantics of the SPICE Package file format.

## Structure

```text
[File Header]<\n>
[Index List]<\n>
[Data List]
```

### File Header

```text
[Index List Offset]<SP>[Index List Length]<\n>
[Information]
```

> **Note** Only ASCII characters are allowed in this section.

- **Index List Offset:** Records the starting offset of the [Index List](#index-list).
- **Index List Length:** Records the length (in bytes) of the [Index List](#index-list).
- **Information:** Metadata for the library file, such as author, copyright and packaging timestamp, etc.

### Index List

```text
[Module Name 1]:[Module Index 1];<\n>
[Module Name 2]:[Module Index 2];<\n>
......
[Module Name N]:[Module Index N];
```

- **Module Name N:** Name of the module. (Must consist only of lowercase letters `a-z` and `-`)
- **Module Index N:** Relative offset from the [Index List Pointer](#file-header). (Must be a hexadecimal value, and one or more hexadecimal digits)

### Data List

```text
[Module 1 Checksum]<SP>[Module 1 Data]
[Module 2 Checksum]<SP>[Module 2 Data]
......
[Module N Checksum]<SP>[Module N Data]
```

> **Note** No newline characters `\n` are allowed.

- **Module N Checksum:** `SHA-256` checksum of the module data.
- **Module N Data:** The ZIP-compressed module data.
