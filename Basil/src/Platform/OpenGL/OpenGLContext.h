#pragma once

#include "Basil/Renderer/GraphicsContext.h"
#include "Platform/Windows/WindowsWindow.hpp"

namespace Basil
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* windowHandle);

        void Init() override;
        void SwapBuffers() override;
    private:
        GLFWwindow* m_WindowHandle;
    };
}
