#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Positron {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// Log pattern
		spdlog::set_pattern("%^[%DT%T%z] %n: %v%$");

		// Core log
		s_CoreLogger = spdlog::stdout_color_mt("POSITRON_CORE");
		s_CoreLogger->set_level(spdlog::level::trace);

		// Client log
		s_ClientLogger = spdlog::stdout_color_mt("POSITRON_CLIENT");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}