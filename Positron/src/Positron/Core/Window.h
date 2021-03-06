#pragma once

#include "pch.h"
#include "Core.h"
#include "Positron/Events/Event.h"

namespace Positron {

  struct WindowProps {
    std::string title;
    uint32_t width;
    uint32_t height;

    WindowProps(const std::string& title = "Positron Engine", uint32_t width = 800, uint32_t height = 600) :
      title(title),
      width(width),
      height(height) {}
  };

  // Interface representing a desktop system based Window
  class POSITRON_API Window {
    public:
    using EventCallbackFn = std::function<void(Event&)>;

    virtual ~Window() = default;

    virtual void OnUpdate() = 0;

    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;

    // Window attributes
    virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
    virtual void SetVSync(bool enabled) = 0;
    virtual bool IsVSync() const = 0;

    static Window* Create(const WindowProps& props = WindowProps());
  };
}