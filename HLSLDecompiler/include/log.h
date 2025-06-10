#pragma once

#include <cstdarg>
#include <string>
#include <ctime>

// Wrappers to make logging cleaner.

extern FILE *LogFile;
extern bool gLogDebug;

// Note that for now I've left the definitions of LogFile and LogDebug as they
// were - either declared locally in a file, as an extern, or from another
// namespace altogether. At some point this needs to be cleaned up, but it's
// probably not worth doing so unless we were switching to use a central
// logging framework.

inline void LogInfo(const char* fmt, ...)
    { if (LogFile) { va_list va; va_start(va, fmt); vfprintf(LogFile, fmt, va); } }
inline void LogInfoW(const wchar_t* fmt, ...)
    { if (LogFile) { va_list va; va_start(va, fmt); vfwprintf(LogFile, fmt, va); } }

inline void LogDebug(const char* fmt, ...)
    { if (gLogDebug) { va_list va; va_start(va, fmt); LogInfo(fmt, va); } }
inline void LogDebugW(const wchar_t* fmt, ...)
    { if (gLogDebug) { va_list va; va_start(va, fmt); LogInfoW(fmt, va); } }

inline std::string LogTime()
{
    char c_time[64];
    tm current_time = {};

    time_t local_time = time(nullptr);
    localtime_s(&current_time, &local_time);
    asctime_s(c_time, sizeof(c_time), &current_time);

    std::string time_str = c_time;
    return time_str;
}

