#pragma once

#include "Basil/Core/Application.hpp"

extern Basil::Application* Basil::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char* argv[])
{
    const auto app = Basil::CreateApplication({ argc, argv });
    app->Run();
    delete app;
}
