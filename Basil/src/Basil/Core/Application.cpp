#include "hzpch.h"
#include "Application.hpp"

#include "Basil/Events/EventDispatcher.hpp"
#include "Basil/Events/KeyEvent.hpp"
#include "Basil/Events/MouseEvent.hpp"
#include "Basil/Events/WindowEvent.hpp"

namespace Basil
{
    Application::Application(const ApplicationSpecification& specification)
    {
        Debug::Init();

        Debug::LogInfo("Initialized application");
        Debug::LogInfo("Initialized application {} - {}", 500, 8964.45f);
        
        m_Window = Window::Create(WindowProps(specification.Name));
    }

    Application::~Application()
    {
        Debug::ShutDown();
    }

    void Application::Run()
    {
        EventDispatcher::Subscribe<WindowCloseEvent>([&](const Ref<WindowCloseEvent>& event)
        {
            m_Running = false;
            event->Handled = true;
        });
        
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

}
