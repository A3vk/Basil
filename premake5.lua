include "Dependencies.lua"

workspace "Basil"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Core"
   include "Basil"
group ""

group "Misc"
   include "Sandbox"
group ""