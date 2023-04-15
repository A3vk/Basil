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
            const fmt::string_view format = message;
            const fmt::format_args formatArgs = fmt::make_format_args(args...);
            s_Logger->trace(fmt::vformat(format, formatArgs));
        }

        template<typename ... Args>
        static void LogDebug(const std::string& message, Args&& ... args)
        {
            const fmt::string_view format = message;
            const fmt::format_args formatArgs = fmt::make_format_args(args...);
            s_Logger->debug(fmt::vformat(format, formatArgs));
        }

        template<typename ... Args>
        static void LogInfo(const std::string& message, Args&& ... args)
        {
            const fmt::string_view format = message;
            const fmt::format_args formatArgs = fmt::make_format_args(args...);
            s_Logger->info(fmt::vformat(format, formatArgs));
        }

        template<typename ... Args>
        static void LogWarn(const std::string& message, Args&& ... args)
        {
            const fmt::string_view format = message;
            const fmt::format_args formatArgs = fmt::make_format_args(args...);
            s_Logger->warn(fmt::vformat(format, formatArgs));
        }

        template<typename ... Args>
        static void LogError(const std::string& message, Args&& ... args)
        {
            const fmt::string_view format = message;
            const fmt::format_args formatArgs = fmt::make_format_args(args...);
            s_Logger->error(fmt::vformat(format, formatArgs));
        }

        template<class... Args>
        static void LogCritical(const std::string& message, Args&& ... args)
        {
            const fmt::string_view format = message;
            const fmt::format_args formatArgs = fmt::make_format_args(args...);
            s_Logger->critical(fmt::vformat(format, formatArgs));
        }

        template<class... Args>
        static void Assert(const bool x, const std::string& message, Args&& ... args)
        {
            if (!x)
            {
                Debug::LogCritical(message, args...);
                Debug::Break();
            }
        }
    
        static void Break();

    private:
        static Ref<spdlog::logger> s_Logger;
    };
}
