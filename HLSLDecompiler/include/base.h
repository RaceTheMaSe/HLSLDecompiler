// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <memory>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <tchar.h>
#include <cstdint>
#include <stdexcept>
#include <cstddef>

#include <cctype>
#include <cwchar>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include <d3d9.h>
#include <d3d11_1.h>
#include <dxgi1_2.h>

#include <d3dcompiler.h>
// #include <directxmath.h>
#include <wrl/client.h>

struct AssemblerParseError final : public std::exception
{
    std::string context, desc, msg;
    int line_no;

    AssemblerParseError(std::string context_, std::string desc_)
    : context(std::move(context_)), desc(std::move(desc_)), line_no(0)
    {
        update_msg();
    }

    void update_msg()
    {
        msg = "Assembly parse error";
        if (line_no > 0)
        {
            msg += std::string(" on line ") + std::to_string(line_no);
        }
        msg += ", " + desc + ":\n\"" + context + "\"";
    }

    const char* what() const 
#if !defined(_MSC_VER) || MSC_VER > 1800 // MSVC 2013 C++11 incomplete
	noexcept
#endif
	override
    {
        return msg.c_str();
    }
};

struct shader_ins
{
	struct bitfield {
		// XXX Beware that bitfield packing is not defined in
		// the C/C++ standards and this is relying on compiler
		// specific packing. This approach is not recommended.

		unsigned opcode : 11;
		unsigned _11_23 : 13;
		unsigned length : 7;
		unsigned extended : 1;
	};
	union {
		bitfield u;
		DWORD op;
	};
};
struct token_operand
{
	struct bitfield {
		// XXX Beware that bitfield packing is not defined in
		// the C/C++ standards and this is relying on compiler
		// specific packing. This approach is not recommended.

		unsigned comps_enum : 2; /* sm4_operands_comps */
		unsigned mode : 2; /* sm4_operand_mode */
		unsigned sel : 8;
		unsigned file : 8; /* SM_FILE */
		unsigned num_indices : 2;
		unsigned index0_repr : 3; /* sm4_operand_index_repr */
		unsigned index1_repr : 3; /* sm4_operand_index_repr */
		unsigned index2_repr : 3; /* sm4_operand_index_repr */
		unsigned extended : 1;
	};
	union {
		bitfield u;
		DWORD op;
	};
};
