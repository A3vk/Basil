#pragma once

#include "Basil/Core/Window.hpp"

namespace Basil
{
    struct ApplicationCommandLineArgs
    {
        int Count = 0;
        char** Args = nullptr;
    };

    struct ApplicationSpecification
    {
        std::string Name = "Basil Application";
        std::string WorkingDirectory;
        ApplicationCommandLineArgs CommandLineArgs;
    };
    
    class Application
    {
    public:
        Application(const ApplicationSpecification& specification);
        virtual ~Application();
        
        void Run();
    private:
        Scope<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication(ApplicationCommandLineArgs args);
}
