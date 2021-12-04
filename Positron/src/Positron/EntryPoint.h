#pragma once

#ifdef POSITRON_PLATFORM_WINDOWS

extern Positron::Application* Positron::CreateApplication();

int main(int argc, char** argv) {
  Positron::Log::Init();
  auto app = Positron::CreateApplication();
  app->Run();
  delete app;
}

#else
#error Positron only supports Windows!
#endif