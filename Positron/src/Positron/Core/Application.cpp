#include "pch.h"
#include "Application.h"


namespace Positron {

  #define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

  Application::Application() {
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    m_Running = true;
  }

  Application::~Application() {}

  void Application::Run() {
    while(m_Running)
      m_Window->OnUpdate();
  }
  void Application::OnEvent(Event& event) {
    CORE_TRACE("{}", event);

    switch(event.GetEventType()) {
      case  EventType::WindowClose:
        m_Running = false;
        break;
    }
  }
}