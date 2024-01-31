#pragma once

#include "base.h"

std::vector<std::string> stringToLines(const char* start, size_t size);

HRESULT disassembler(std::vector<byte> *buffer, std::vector<byte> *ret, const char *comment,
		int hexdump = 0, bool d3dcompiler_46_compat = false,
		bool disassemble_undecipherable_data = false,
		bool patch_cb_offsets = false);

HRESULT disassemblerDX9(std::vector<byte> *buffer, std::vector<byte> *ret, const char *comment);

std::vector<byte> assembler(std::vector<char> *asmFile, std::vector<byte> origBytecode, std::vector<AssemblerParseError> *parse_errors = nullptr);

std::vector<byte> assemblerDX9(std::vector<char> *asmFile);

void writeLUT();