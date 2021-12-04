#pragma once

#include <memory>

#include "Core.h"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#pragma warning(pop)

namespace Positron {
	class POSITRON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetCLientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define POSITRON_CORE_TRACE(...)   ::Positron::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define POSITRON_CORE_INFO(...)      ::Positron::Log::GetCoreLogger()->info(__VA_ARGS__)
#define POSITRON_CORE_WARN(...)      ::Positron::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define POSITRON_CORE_ERROR(...)     ::Positron::Log::GetCoreLogger()->error(__VA_ARGS__)
#define POSITRON_CORE_CRITICAL(...)  ::Positron::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)               ::Positron::Log::GetCLientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)                ::Positron::Log::GetCLientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)                ::Positron::Log::GetCLientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)               ::Positron::Log::GetCLientLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)            ::Positron::Log::GetCLientLogger()->critical(__VA_ARGS__)
