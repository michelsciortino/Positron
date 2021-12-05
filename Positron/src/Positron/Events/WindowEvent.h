#pragma once

#include "Event.h"
#include <format>

namespace Positron {

  class POSITRON_API WindowEvent : public Event {
    public:

    inline virtual std::string ToString() const override GET("WindowEvent");

    EVENT_CLASS_CATEGORY(EventCategoryWindow)
  };

  class POSITRON_API WindowCloseEvent : public WindowEvent {
    public:
    WindowCloseEvent() {}

    inline std::string ToString() const override GET("WindowCloseEvent");

    EVENT_CLASS_TYPE(EventType::WindowClose)
  };

  class POSITRON_API WindowResizeEvent : public WindowEvent {
    public:
    WindowResizeEvent(unsigned int width, unsigned int height) :
      m_Width(width),
      m_Height(height) {}

    inline unsigned int GetWidth() const GET(m_Width);

    inline unsigned int GetHeight() const GET(m_Height);

    inline std::string ToString() const override GET(F("WindowResizeEvent: {},{}", m_Width, m_Height));

    EVENT_CLASS_TYPE(EventType::WindowResize)

    private:
    unsigned int m_Width, m_Height;
  };

  class POSITRON_API WindowFocusEvent : public WindowEvent {
    public:
    WindowFocusEvent() {}

    inline std::string ToString() const override GET(F("WindowFocusEvent"));

    EVENT_CLASS_TYPE(EventType::WindowFocus)
  };

  class POSITRON_API WindowMovedEvent : public WindowEvent {
    public:
    WindowMovedEvent() {}

    inline std::string ToString() const override GET(F("WindowMovedEvent"));

    EVENT_CLASS_TYPE(EventType::WindowMoved)
  };
}