workspace "Template"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Template/../vendor/GLFW/include"
IncludeDir["Glad"] = "Template/../vendor/Glad/include"
IncludeDir["ImGui"] = "Template/../vendor/imgui"
IncludeDir["glm"] = "Template/../vendor/glm"
IncludeDir["stb_image"] = "Template/../vendor/stb_image"
IncludeDir["spdlog"] = "Template/../vendor/spdlog/include"

project "Template"
	location "Template"
	kind "consoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.spdlog}",
	}

	links 
	{ 
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

		postbuildcommands
		{
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"
