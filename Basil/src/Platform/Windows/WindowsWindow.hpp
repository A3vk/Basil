#pragma once

#include "Basil/Core/Window.hpp"
#include "Basil/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Basil
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        ~WindowsWindow() override;
        
        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; }
        unsigned int GetHeight() const override { return m_Data.Height; }

        void SetVSync(bool enabled) override;
        bool IsVSync() const override { return m_Data.VSync; }
        
    private:
        void Init(const WindowProps& props);
        void Shutdown();

        GLFWwindow* m_Window;
        Scope<GraphicsContext> m_Context;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
        };

        WindowData m_Data;
    };
}
