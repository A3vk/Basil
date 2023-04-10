project "Basil"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "src/hzpch.cpp"

	files {
		"src/**.h",
		"src/**.hpp",
		"src/**.cpp"
	}

	defines {
		"GLFW_INCLUDE_NONE"
	}

	includedirs {
		"src",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links {
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines { "BASIL_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "BASIL_RELEASE" }
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines { "BASIL_DIST" }
		runtime "Release"
		optimize "On"
		symbols "Off"