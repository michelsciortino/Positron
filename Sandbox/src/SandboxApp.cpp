#include <Positron.h>

class Sandbox : public Positron::Application {
  public:
  Sandbox() {}

  ~Sandbox() {}

  void Run() {
    LOG_INFO("RUN");
  }
};

Positron::Application* Positron::CreateApplication() {
  return new Sandbox();
}