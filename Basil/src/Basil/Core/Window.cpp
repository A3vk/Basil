#include "hzpch.h"
#include "Window.hpp"

#include "Platform/Windows/WindowsWindow.hpp"

namespace Basil
{
    std::unique_ptr<Window> Window::Create(const WindowProps& props)
    {
        return CreateScope<WindowsWindow>(props);
    }
}
