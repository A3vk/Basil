#include "hzpch.h"
#include "Debug.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Basil
{
    Ref<spdlog::logger> Debug::s_Logger;

    void Debug::Init()
    {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Basil.log", true));

        logSinks[0]->set_pattern("%^[%T] %n: %v%$");
        logSinks[1]->set_pattern("[%T] [%l] %n: %v");

        s_Logger = CreateRef<spdlog::logger>("BASIL", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_Logger);
        s_Logger->set_level(spdlog::level::trace);
        s_Logger->flush_on(spdlog::level::trace);
    }

    void Debug::ShutDown()
    {
        spdlog::shutdown();
    }

    bool Debug::IsDebugBuild()
    {
#ifdef BASIL_DEBUG
        return true;
#else
        return false;
#endif
    }

    bool Debug::IsReleaseBuild()
    {
#ifdef BASIL_RELEASE
        return true;
#else
        return false;
#endif
    }

    void Debug::Break()
    {
        __debugbreak();
    }
}
