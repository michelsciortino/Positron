#pragma once

#include "Event.h"
#include <Positron/Core/InputCodes.h>
#include <Positron/Core/Geometry.h>

namespace Positron {

  class POSITRON_API MouseEvent : public Event {

    public:

    inline double GetXpos() const GET(m_Xpos);
    inline double GetYpos() const GET(m_Ypos);

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    protected:
    MouseEvent(double xpos, double ypos) : m_Xpos(xpos), m_Ypos(ypos) {}

    double m_Xpos, m_Ypos;
  };

  class POSITRON_API MouseButtonEvent : public MouseEvent {

    public:

    inline Input::InputCode GetButtonCode() const GET(m_buttonCode);

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)

    protected:
    MouseButtonEvent(Input::InputCode code, double xpos, double ypos) : MouseEvent(xpos, ypos), m_buttonCode(code) {}

    Input::InputCode m_buttonCode;
  };


  class POSITRON_API MouseDownEvent : public MouseButtonEvent {

    public:
    MouseDownEvent(Input::InputCode code, double xpos, double ypos) : MouseButtonEvent(code, xpos, ypos) {}

    inline std::string ToString() const override GET(F("MouseDownEvent: button {}, point ({:.1f}, {:.1f})", m_buttonCode, m_Xpos, m_Ypos));

    EVENT_CLASS_TYPE(EventType::MouseButtonDown)
  };


  class POSITRON_API MouseUpEvent : public MouseButtonEvent {

    public:
    MouseUpEvent(Input::InputCode code, double xpos, double ypos) : MouseButtonEvent(code, xpos, ypos) {}

    inline std::string ToString() const override GET(F("MouseUpEvent: button {}, point ({:.1f}, {:.1f})", m_buttonCode, m_Xpos, m_Ypos));

    EVENT_CLASS_TYPE(EventType::MouseButtonUp)
  };


  class POSITRON_API MouseMovedEvent : public MouseEvent {

    public:
    MouseMovedEvent(double xpos, double ypos) : MouseEvent(xpos, ypos) {}

    inline std::string ToString() const override GET(F("MouseMovedEvent: point ({:.1f}, {:.1f})", m_Xpos, m_Ypos));

    EVENT_CLASS_TYPE(EventType::MouseMoved)
  };

  class POSITRON_API MouseScrolledEvent : public MouseEvent {

    public:
    MouseScrolledEvent(double xoffset, double yoffset, double xpos, double ypos) : MouseEvent(xpos, ypos), m_Xoffset(xoffset), m_Yoffset(yoffset) {}

    inline double GetXoffset() const GET(m_Xoffset);

    inline double GetYoffset() const GET(m_Yoffset);

    inline std::string ToString() const override GET(F("MouseScrolledEvent: offset ({:.1f}, {:.1f}), point ({:.1f}, {:.1f})", m_Xoffset, m_Yoffset, m_Xpos, m_Ypos));

    EVENT_CLASS_TYPE(EventType::MouseScrolled)

    private:
    double m_Xoffset, m_Yoffset;
  };
}