#pragma once

#include <Positron/Core/Core.h>
#include <Positron/Core/Window.h>
#include <Positron/Core/LayerStack.h>

namespace Positron {
  class POSITRON_API Application {
    public:
    Application();

    virtual ~Application();

    virtual void Run();

    virtual void OnEvent(Event& event);

    protected:
    LayerStack m_LayerStack;

    private:
    std::unique_ptr<Window> m_Window;
    bool m_Running;
  };

  //To be defined in a Client
  Application* CreateApplication();

}