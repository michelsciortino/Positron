#include <Positron.h>

class Sandbox : public Positron::Application {
  public:
  Sandbox() {}

  ~Sandbox() {}
};

namespace Positron {

  Application* CreateApplication() {
    return new Sandbox();
  }

}