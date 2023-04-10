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
        std::unique_ptr<Window> m_Window;
    };

    Application* CreateApplication(ApplicationCommandLineArgs args);
}
