#include "hzpch.h"
#include "WindowsWindow.hpp"

namespace Basil
{
    static uint8_t GLFWWindowCount = 0;

    static void GLFWErrorCallback(int error, const char* description)
    {
        Debug::LogError("GLFW Error ({}): {}", error, description);
    }
    
    WindowsWindow::WindowsWindow(const WindowProps& props) : m_Window(nullptr), m_Context(nullptr)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        Debug::LogInfo("Creating window {} ({}, {})", props.Title, props.Width, props.Height);

        if (GLFWWindowCount == 0)
        {
            const int success = glfwInit();
            Debug::Assert(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
        }

#ifdef BASIL_DEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

        m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), props.Title.c_str(), nullptr, nullptr);
        ++GLFWWindowCount;

        m_Context = GraphicsContext::Create(m_Window);
        m_Context->Init();

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
        --GLFWWindowCount;

        if (GLFWWindowCount == 0)
        {
            glfwTerminate();
        }
    }
}