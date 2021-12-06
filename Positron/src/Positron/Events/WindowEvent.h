#pragma once

#include "Event.h"

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

    inline std::string ToString() const override GET(F("WindowResizeEvent: {}, {}", m_Width, m_Height));

    EVENT_CLASS_TYPE(EventType::WindowResize)

    private:
    unsigned int m_Width, m_Height;
  };

  class POSITRON_API WindowFocusedEvent : public WindowEvent {
    public:
    WindowFocusedEvent() {}

    inline std::string ToString() const override GET("WindowFocusEvent");

    EVENT_CLASS_TYPE(EventType::WindowFocus)
  };

  class POSITRON_API WindowLostFocusEvent : public WindowEvent {
    public:
    WindowLostFocusEvent() {}

    inline std::string ToString() const override GET("WindowLostFocusEvent");

    EVENT_CLASS_TYPE(EventType::WindowLostFocus)
  };

  class POSITRON_API WindowMovedEvent : public WindowEvent {
    public:
    WindowMovedEvent(int xpos, int ypos) : m_Xpos(xpos), m_Ypos(ypos) {}

    inline int GetXpos() const GET(m_Xpos);

    inline int GetYpos() const GET(m_Ypos);

    inline std::string ToString() const override GET(F("WindowMovedEvent: ({}, {})", m_Xpos, m_Ypos));

    EVENT_CLASS_TYPE(EventType::WindowMoved);

    private:
    int m_Xpos, m_Ypos;
  };

  class POSITRON_API WindowRefreshedEvent : public WindowEvent {
    public:
    WindowRefreshedEvent() {}

    inline std::string ToString() const override GET(F("WindowRefreshedEvent"));

    EVENT_CLASS_TYPE(EventType::WindowRefreshed)
  };

  class POSITRON_API WindowIconifiedEvent : public WindowEvent {
    public:
    WindowIconifiedEvent() {}

    inline std::string ToString() const override GET(F("WindowIconifiedEvent"));

    EVENT_CLASS_TYPE(EventType::WindowIconfied)
  };

  class POSITRON_API WindowUniconifiedEvent : public WindowEvent {
    public:
    WindowUniconifiedEvent() {}

    inline std::string ToString() const override GET(F("WindowUniconifiedEvent"));

    EVENT_CLASS_TYPE(EventType::WindowUniconified)
  };

  class POSITRON_API WindowMaximizedEvent : public WindowEvent {
    public:
    WindowMaximizedEvent() {}

    inline std::string ToString() const override GET(F("WindowMaximizedEvent"));

    EVENT_CLASS_TYPE(EventType::WindowMaximized)
  };

  class POSITRON_API WindowUnmaximizedEvent : public WindowEvent {
    public:
    WindowUnmaximizedEvent() {}

    inline std::string ToString() const override GET(F("WindowUnmaximizedEvent"));

    EVENT_CLASS_TYPE(EventType::WindowUnmaximized)
  };

  class POSITRON_API WindowContentScaledEvent : public WindowEvent {
    public:
    WindowContentScaledEvent(float xScale, float yScale) : m_XScale(xScale), m_YScale(yScale) {}

    inline float GetXScale() const GET(m_XScale);

    inline float GetYScale() const GET(m_YScale);

    inline std::string ToString() const override GET(F("WindowContentScaledEvent: ({}, {})", m_XScale, m_YScale));

    EVENT_CLASS_TYPE(EventType::WindowUnmaximized)

    private:
    float m_XScale, m_YScale;
  };
}