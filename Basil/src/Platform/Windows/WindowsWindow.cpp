#include "hzpch.h"
#include "WindowsWindow.hpp"

#include "Basil/Events/EventDispatcher.hpp"
#include "Basil/Events/KeyEvent.hpp"
#include "Basil/Events/MouseEvent.hpp"
#include "Basil/Events/WindowEvent.hpp"

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

        // Key events
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (action == GLFW_PRESS)
            {
                EventDispatcher::Dispatch(CreateRef<KeyPressedEvent>(key));
            }
            else if (action == GLFW_RELEASE)
            {
                EventDispatcher::Dispatch(CreateRef<KeyReleasedEvent>(key));
            }
            else if (action == GLFW_RELEASE)
            {
                EventDispatcher::Dispatch(CreateRef<KeyPressedEvent>(key, true));
            }
        });
        
        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint)
        {
            EventDispatcher::Dispatch(CreateRef<KeyTypedEvent>(codepoint));
        });
        
        // Mouse events
        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            EventDispatcher::Dispatch(CreateRef<MouseMovedEvent>(xPos, yPos));
        });
        
        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            if (action == GLFW_PRESS)
            {
                EventDispatcher::Dispatch(CreateRef<MouseButtonPressedEvent>(button));
            }
            else if (action == GLFW_RELEASE)
            {
                EventDispatcher::Dispatch(CreateRef<MouseButtonReleasedEvent>(button));
            }
        });
        
        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            EventDispatcher::Dispatch(CreateRef<MouseScrolledEvent>(xOffset, yOffset));
        });
        
        // Window events
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            EventDispatcher::Dispatch(CreateRef<WindowCloseEvent>());
        });
        
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            EventDispatcher::Dispatch(CreateRef<WindowResizeEvent>(width, height));
        });
        
        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
        {
            if (focused)
            {
                EventDispatcher::Dispatch(CreateRef<WindowFocusEvent>());
            }
            else
            {
                EventDispatcher::Dispatch(CreateRef<WindowLostFocusEvent>());                
            }
        });
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
