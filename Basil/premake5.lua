project "Basil"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"src/**.hpp",
		"src/**.cpp"
	}

	includedirs {
		"src",
		"%{IncludeDir.spdlog}",
	}

	filter "system:windows"
		systemversion "latest"
		defines { "BASIL_PLATFORM_WINDOWS" }

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