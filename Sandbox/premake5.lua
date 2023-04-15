project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"src/**.h",
		"src/**.hpp",
		"src/**.cpp"
	}

	includedirs {
		"%{wks.location}/Basil/src",
		"%{wks.location}/Basil/vendor",
		"%{wks.location}/Basil/vendor/spdlog/include"
	}

	links {
		"Basil"
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
		kind "WindowedApp"
		defines { "BASIL_DIST" }
		runtime "Release"
		optimize "On"
		symbols "Off"