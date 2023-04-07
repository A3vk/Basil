#pragma once
#include <memory>

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

class Debug
{
public:
    static void Init();

    static bool IsDebugBuild();
    static bool IsReleaseBuild();
    
    template<class... Args>
    static void LogTrace(const std::string& message, const Args&... args)
    {
        s_Logger->info(message, args...);
    }

    template<class... Args>
    static void LogDebug(const std::string& message, const Args&... args)
    {
        s_Logger->debug(message, args...);
    }

    template<class... Args>
    static void LogInfo(const std::string& message, const Args&... args)
    {
        s_Logger->info(message, args...);
    }

    template<class... Args>
    static void LogWarn(const std::string& message, const Args&... args)
    {
        s_Logger->warn(message, args...);
    }

    template<class... Args>
    static void LogError(const std::string& message, const Args&... args)
    {
        s_Logger->error(message, args...);
    }

    template<class... Args>
    static void LogCritical(const std::string& message, const Args&... args)
    {
        s_Logger->critical(message, args...);
    }

    template<class... Args>
    static void Assert(const bool x, const std::string& message, const Args&... args)
    {
        if (!x)
            Debug::LogCritical(message, args...);
    }
    
    static void Break();

private:
    static std::shared_ptr<spdlog::logger> s_Logger;
};
