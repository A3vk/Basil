include "Dependencies.lua"

workspace "Basil"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
   include "Basil/vendor/GLFW_premake5.lua"
   include "Basil/vendor/Glad"
group ""

group "Core"
   include "Basil"
group ""

group "Misc"
   include "Sandbox"
group ""