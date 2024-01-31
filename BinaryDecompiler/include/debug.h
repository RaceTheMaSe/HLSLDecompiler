#pragma once

#include <cassert>

#if defined(_DEBUG)
#define ASSERT(expr) CustomAssert(expr)
static void CustomAssert(int expression)
{
    if(!expression)
    {
        assert(0);
    }
}
#else
#define ASSERT(expr)
#endif