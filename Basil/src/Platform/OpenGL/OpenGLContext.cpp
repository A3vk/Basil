#include "hzpch.h"
#include "OpenGLContext.h"

#include "glad/glad.h"

namespace Basil
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
    {
        Debug::Assert(windowHandle, "Window handle is null!");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        const int status = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
        Debug::Assert(status, "Failed to initialize Glad!");
        Debug::Assert(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Basil requires at least OpenGL version 4.5!");
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}
