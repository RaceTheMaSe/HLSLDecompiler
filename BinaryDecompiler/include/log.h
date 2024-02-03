#pragma once

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

#define LogInfo(fmt, ...) \
    do { if (LogFile) fprintf(LogFile, fmt, __VA_ARGS__); } while (0)
#define vLogInfo(fmt, va_args) \
    do { if (LogFile) vfprintf(LogFile, fmt, va_args); } while (0)
#define LogInfoW(fmt, ...) \
    do { if (LogFile) fwprintf(LogFile, fmt, __VA_ARGS__); } while (0)

#define LogDebug(fmt, ...) \
    do { if (gLogDebug) LogInfo(fmt, __VA_ARGS__); } while (0)
#define vLogDebug(fmt, va_args) \
    do { if (gLogDebug) vLogInfo(fmt, va_args); } while (0)
#define LogDebugW(fmt, ...) \
    do { if (gLogDebug) LogInfoW(fmt, __VA_ARGS__); } while (0)

static std::string LogTime()
{
    char c_time[64];
    tm current_time = {};

    time_t local_time = time(nullptr);
    localtime_s(&current_time, &local_time);
    asctime_s(c_time, sizeof(c_time), &current_time);

    std::string time_str = c_time;
    return time_str;
}

