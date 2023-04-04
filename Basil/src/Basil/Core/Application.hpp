#pragma once
#include <string>

// int main(int argc, char** argv);

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
        // virtual ~Application();
        
        void Run();
    };

    Application* CreateApplication(ApplicationCommandLineArgs args);
}
