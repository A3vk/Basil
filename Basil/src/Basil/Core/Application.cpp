#include "hzpch.h"
#include "Application.hpp"

namespace Basil
{
    Application::Application(const ApplicationSpecification& specification)
    {
        Debug::Init();

        Debug::LogInfo("Initialized application");
        
        m_Window = Window::Create(WindowProps(specification.Name));
    }

    Application::~Application()
    {
        Debug::ShutDown();
    }

    void Application::Run()
    {
        while (true)
        {
            m_Window->OnUpdate();
        }
    }

}
