#pragma once

#include "base.h"

HRESULT AssembleFluganWithSignatureParsing(std::vector<char> *assembly, std::vector<byte> *result_bytecode, std::vector<AssemblerParseError> *parse_errors = nullptr);

std::vector<byte> AssembleFluganWithOptionalSignatureParsing(std::vector<char> *assembly, bool assemble_signatures, 
            std::vector<byte> *orig_bytecode, std::vector<AssemblerParseError> *parse_errors = nullptr);