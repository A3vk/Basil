﻿#pragma once

#include "Basil/Core/Base.hpp"

#include <string>

namespace Basil
{
    struct WindowProps
    {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string& title = "Basil Window", const uint32_t width = 1600, const uint32_t height = 900) : Title(title), Width(width), Height(height) {}
    };
    
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Scope<Window> Create(const WindowProps& props = WindowProps());
    };
}
