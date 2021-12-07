#pragma once

#include "Positron/Core/Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Positron {

  class Win32Window : public Positron::Window {
    public:
    Win32Window(const WindowProps& props);
    virtual ~Win32Window();

    void OnUpdate() override;

    inline uint32_t GetWidth() const override GET(m_Data.width);
    inline uint32_t GetHeight() const override GET(m_Data.height);

    //Window attrivutes
    inline void SetEventCallback(const EventCallbackFn& cb) override SET(m_Data.EventCallback, cb);
    void SetVSync(bool enabled) override;
    bool IsVSync() const override;

    private:

    virtual void Init(const WindowProps& props);
    virtual void Shutdown();

    struct WindowData {
      std::string title;
      uint32_t width, height;
      bool vSync;
      EventCallbackFn EventCallback;
    };

    WindowData m_Data;
    GLFWwindow* m_Window;
  };
}