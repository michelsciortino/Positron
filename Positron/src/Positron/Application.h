#pragma once

#include "Core.h"

namespace Positron {
	class POSITRON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:

	};

	//To be defined in a Client
	Application* CreateApplication();
}