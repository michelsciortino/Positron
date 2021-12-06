#pragma once

#include "Core.h"
#include "Window.h"

namespace Positron {
  class POSITRON_API Application {
    public:
    Application();

    virtual ~Application();

    virtual void Run();

    virtual void OnEvent(Event& event);

    private:
    std::unique_ptr<Window> m_Window;
    bool m_Running;
  };

  //To be defined in a Client
  Application* CreateApplication();

}