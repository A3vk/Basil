#pragma once

#include "Basil/Core/Base.hpp"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#pragma warning(pop)

namespace Basil
{
    class Debug
    {
    public:
        static void Init();
        static void ShutDown();

        static bool IsDebugBuild();
        static bool IsReleaseBuild();
    
        template<typename ... Args>
        static void LogTrace(const std::string& message, Args&& ... args)
        {
            s_Logger->info(message, std::forward<Args>(args)...);
        }

        template<typename ... Args>
        static void LogDebug(const std::string& message, Args&& ... args)
        {
            s_Logger->debug(message, std::forward<Args>(args)...);
        }

        template<typename ... Args>
        static void LogInfo(const std::string& message, Args&& ... args)
        {
            s_Logger->info(message, std::forward<Args>(args)...);
        }

        template<typename ... Args>
        static void LogWarn(const std::string& message, Args&& ... args)
        {
            s_Logger->warn(message, std::forward<Args>(args)...);
        }

        template<typename ... Args>
        static void LogError(const std::string& message, Args&& ... args)
        {
            s_Logger->error(message, std::forward<Args>(args)...);
        }

        template<class... Args>
        static void LogCritical(const std::string& message, Args&& ... args)
        {
            s_Logger->critical(message, std::forward<Args>(args)...);
        }

        template<class... Args>
        static void Assert(const bool x, const std::string& message, Args&& ... args)
        {
            if (!x)
            {
                Debug::LogCritical(message, std::forward<Args>(args)...);
                Debug::Break();
            }
        }
    
        static void Break();

    private:
        static Ref<spdlog::logger> s_Logger;
    };
}
