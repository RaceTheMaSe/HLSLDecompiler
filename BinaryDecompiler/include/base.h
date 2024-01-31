// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <cstdio>
#include <tchar.h>
#include <cstdint>
#include <D3DCompiler.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

// VS2013 BUG WORKAROUND: Make sure this class has a unique type name!
struct AssemblerParseError: public std::exception 
{
	std::string context, desc, msg;
	int line_no;

	AssemblerParseError(std::string context_, std::string desc_) :
		context(std::move(context_)),
		desc(std::move(desc_)),
		line_no(0)
	{
		update_msg();
	}

	void update_msg()
	{
		msg = "Assembly parse error";
		if (line_no > 0)
			msg += std::string(" on line ") + std::to_string(line_no);
		msg += ", " + desc + ":\n\"" + context + "\"";
	}

	const char* what() const override
	{
		return msg.c_str();
	}
};

struct shader_ins
{
	union {
		struct {
			// XXX Beware that bitfield packing is not defined in
			// the C/C++ standards and this is relying on compiler
			// specific packing. This approach is not recommended.

			unsigned opcode : 11;
			unsigned _11_23 : 13;
			unsigned length : 7;
			unsigned extended : 1;
		};
		DWORD op;
	};
};
struct token_operand
{
	union {
		struct {
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
		DWORD op;
	};
};
