workspace "Positron"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Positron"
	location "Positron"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"POSITRON_PLATFORM_WINDOWS",
			"POSITRON_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .."\\Sandbox")
		}

	filter "configurations:Debug"
		defines "POSITRON_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POSITRON_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POSITRON_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Positron/vendor/spdlog/include",
		"Positron/src"
	}

	links
	{
		"Positron"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"POSITRON_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "POSITRON_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POSITRON_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POSITRON_DIST"
		optimize "On"