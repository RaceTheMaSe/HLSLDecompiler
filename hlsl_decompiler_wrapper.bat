@echo off

rem USAGE:
rem 	1. Put this batch file and CMD_Decompiler.exe in the same directory
rem 	2. RenderDoc -> Tools -> Settings -> Shader Viewer -> Add
rem 		2.1. Name: Whatever you like
rem 		2.2. Tool Type: Custom Tool
rem 		2.3. Executable: Choose this batch file instead of CMD_Decompiler.exe
rem 		2.4. Command Line: {input_file}
rem 		2.5. Input/Output: DXBC/HLSL
rem 	3. RenderDoc -> Pipeline State View -> Choose Any Shader Stage
rem 		3.1. Edit -> Decompile with ${Name}
rem 	4. Modify shader as you wish, and click Refresh button to see the change

: decompile input_file
"%~dp0CMD_Decompiler.exe" -D "%1"

: redirect to stdout
for %%f in ("%1") do type "%%~dpnf.hlsl"
