# Data Stuctures and Algorithms: C++ Version


## C++ Development Environment Setup (VS Code)

This guide will help you set up a complete modern C++ development environment for this Data Structures & Algorithms repository using Visual Studio Code.

This project uses:
- C++17
- CMake
- clang-format (auto formatting)

Follow the steps below carefully.

### 1. Install a C++ Compiler

You need a C++17 compatible compiler.

**Windows**

1. Install MinGW-w64
https://www.mingw-w64.org/
2. During installation, make sure the bin folder is added to your system PATH.
3. Verify installation:
```
g++ --version
```

**macOS**

Install Xcode Command Line Tools:
```
xcode-select --install
```

Verify:
```
clang++ --version
```

**Linux (Ubuntu / Debian)**

```
sudo apt update
sudo apt install build-essential
```

Verify:

```
g++ --version
```

### 2. Install CMake

This project uses CMake for building.

**Windows**

Download and install from:
https://cmake.org/download/

> IMPORTANT: During installation, select “Add CMake to system PATH”

**macOS**

```
brew install cmake
```

**Linux (Ubuntu / Debian)**

```
sudo apt install cmake
```

Verify CMake Installation

```
cmake --version
```

If this fails, CMake is either not installed or not added to PATH.

Minimum required version: 3.16+

### 3. Install Visual Studio Code

Download from:
https://code.visualstudio.com/

### 4. Install Required VS Code Extensions

Open VS Code → Extensions → Install:
- C/C++ (Microsoft)
- CMake Tools (Microsoft)

These are required.

### 5. Fix “Bad CMake Executable” Error (Important)

If you see this popup:

> Bad CMake executable: “”

It means VS Code cannot find CMake.

#### General Fix
1. Open terminal in VS Code.
2. Run:
```
cmake --version
```
If it fails:
- Install CMake properly
- Make sure it is added to PATH
- Restart VS Code completely

If it works but VS Code still complains:

3. Open Settings (JSON) and remove any empty entry like:
```
"cmake.cmakePath": ""
```

4. Restart VS Code.

In most cases, restarting VS Code after installing CMake fixes the issue.

#### Manual Fix

If the previous steps doesn't solve the issue, you have to set the **cmakePath** manually.

1. Open terminal in VS Code.
2. Run:
```
which cmake
```

You should see something like:
> In macOs: /opt/homebrew/bin/cmake

> In Windows: C:/Program Files/CMake/bin/cmake.exe

3. Open Settings (JSON) and remove any empty entry like:
```
"cmake.cmakePath": "/opt/homebrew/bin/cmake"
```

4. Restart VS Code.

### 6. Clone and Open the Project

```
git clone https://github.com/DhanushkaSandakelum/dsa-cpp
cd dsa-cpp
code .
```

### 7. Build the Project (Manual Method)

Create a build directory:

```
mkdir build
cd build
cmake ..
cmake --build .
```

Executables will be generated in:

```
build/bin/
```

Run example:

**macOS / Linux**

```
./bin/static_array_demo
```

**Windows**

```
bin\static_array_demo.exe
```

### 8. Enable Auto Formatting (clang-format)

This project includes a .clang-format file.

To enable formatting on save:
1. Open VS Code Settings
2. Enable:
    - Format On Save
    - Default Formatter → C/C++ (Microsoft)

Or add this to .vscode/settings.json:

```json
{
    "C_Cpp.clang_format_style": "file",
    "C_Cpp.formatting": "clangFormat",
    "editor.formatOnSave": true,

    "editor.defaultFormatter": "ms-vscode.cpptools",

    "[cpp]": {
        "editor.formatOnSave": true
    }
}
```

Now your C++ code will auto-format according to the project rules whenever you save.

### 9. Verify Setup

Create a simple test file:

```cpp
#include <iostream>

int main() {
    std::cout << "C++ setup successful!\n";
    return 0;
}
```

Build and run it.
If it prints correctly, your environment is ready.

### 10. Final Checklist

Make sure the following work:
- g++ –version (or clang++)
- cmake –version
- VS Code installed
- C/C++ extension installed
- CMake Tools extension installed
- Format on save working