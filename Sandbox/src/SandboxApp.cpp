#include <Positron.h>

class TestLayer : public Positron::Layer {
  public:
  TestLayer() : Layer("Test") {}

  void OnAttach() override {
    LOG_INFO("Layer {} attached", m_Name);
  }

  void OnEvent(Positron::Event& event) override {
    LOG_INFO("Layer {} received event {}", m_Name, event);
  }
};

class Sandbox : public Positron::Application {
  public:
  Sandbox() : Application() {
    std::shared_ptr layer = std::make_shared<TestLayer>();
    m_LayerStack.PushFront(layer);
  }

  ~Sandbox() {}
};

namespace Positron {

  Application* CreateApplication() {
    return new Sandbox();
  }

}