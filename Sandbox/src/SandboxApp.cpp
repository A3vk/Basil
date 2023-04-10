#include <Basil.hpp>
#include <Basil/Core/EntryPoint.hpp>

class Sandbox : public Basil::Application
{
public:
    Sandbox(const Basil::ApplicationSpecification& specification) : Application(specification) {
        
    }

    ~Sandbox()
    {
        
    }
};

Basil::Application* Basil::CreateApplication(ApplicationCommandLineArgs args)
{
    ApplicationSpecification spec;
    spec.Name = "Sandbox";
    spec.CommandLineArgs = args;
    
    return new Sandbox(spec);
}