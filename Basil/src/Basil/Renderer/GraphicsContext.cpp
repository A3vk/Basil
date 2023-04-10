#include "hzpch.h"
#include "GraphicsContext.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace Basil
{
    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {
        return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
    }
}
