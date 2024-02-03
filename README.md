# Introduction
Translate dxbc to hlsl source code. You can use it alone, or as a shader processing tool in RenderDoc to decompile shader. Although the decompiled result looks very like the disassembly, you can edit the decompiled source code and refresh to see the change in RenderDoc. It's very useful while learning and analyzing rendering techniques in games if you don't have source code.

# Features
- Support shader model 4 and shader model 5
- Covert shader binary to dxbc or hlsl source code
- Covert dxbc source code to shader binary, you can modify dxbc code and apply modification to pipeline state

# ToDo
- Support shader model 6

# Getting started
```shell
# Compile 
git clone https://github.com/YUZHIGUIYI/HLSLDecompiler.git
cd HLSLDecompiler
cmake -DCMAKE_BUILD_TYPE=Debug -B build
cmake --build build --config=Release
# Usage
cd bin
./CMD_Decompiler.exe
```

# Integrate into RenderDoc
1. Put `hlsl_decompiler_wrapper.bat` and `CMD_Decompiler.exe` in the same directory
2. RenderDoc -> Tools -> Settings -> Shader Viewer -> Add
    | Field | Value |
    |------|:--------------:|
    | Name | HLSLDecompiler |
    | Tool Type | Custom Tool |
    | Executable | Set absolute path of `hlsl_decompiler_wrapper.bat` |
    | Command Line | {input_file} |
    | Input/Output | DXBC/HLSL |

3. RenderDoc -> Pipeline State View -> Choose Any Shader Stage -> Edit -> Decompile with ${Name}
4. Modify shader as you wish, and click Refresh button to see the change
