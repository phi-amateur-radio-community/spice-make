# SPICE Make Package Remote Library Format

> **Last Edit: 2026-09-12**

## Overview

This document describes the repository structure of the remote library.

## Structure

### Remote Repository Structure

```text
repos.example.com/spice
├── repos.json
├── repos.json.sig  (recommend)
├── PUBLIC          (recommend)
└── library
   ├── [Author 1]
   │  ├── author.json
   │  ├── [Module 1]
   │  │  ├── module.json
   │  │  ├── <Author>.<Module>.<Version>.zst.tar
   │  │  └── ...
   │  ├── [Module 2]
   │  └── ...
   ├── [Author 2]
   └── ...
```

### File of Repository

#### `repos.json`

```json
{
  "name": "Example Repository",
  "timestamp": "1789199570712",
  "authors": [
    {
      "name": "Author 1",
      "signature": "Base64(GPG(author.json))",
      "timestamp": "1789199570712"
    }
  ],
  "publicKey": "PUBLIC",
  "domain": "repos.exmaple.com"
}
```

#### `author.json`

```json
{
  "name": "Author 1",
  "timestamp": "1789199570712",
    "authors": [
      {
        "name": "Module 1",
        "signature": "Base64(GPG(module.json))",
        "timestamp": "1789199570712"
      }
    ]
  }
```

#### `module.json`

```json
{
  "name": "Author 1",
  "timestamp": "1789199570712",
    "authors": [
      {
        "name": "Version 1",
        "signature": "Base64(GPG(xxx.zst.tar))",
        "timestamp": "1789199570712"
      }
    ]
  }
```

---

**Copyright (c) 2026 Phiarc Teams.**  
**This document adopts the [Creative Commons Attribution-ShareAlike 4.0 Unported](https://creativecommons.org/licenses/by-sa/4.0/).**
