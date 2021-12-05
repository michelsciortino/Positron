#pragma once

#include "Event.h"
#include <Positron/Core/InputCodes.h>
#include <Positron/Core/Geometry.h>

namespace Positron {

  class POSITRON_API MouseEvent : public Event {

    public:

    inline Point2D GetPosition() const GET(m_Point);

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    protected:
    MouseEvent(Point2D point) : m_Point(point) {}

    Point2D m_Point;
  };

  class POSITRON_API MouseButtonEvent : public MouseEvent {

    public:

    inline Input::InputCode GetButtonCode() const GET(m_buttonCode);

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)

    protected:
    MouseButtonEvent(Input::InputCode code, Point2D point) : MouseEvent(point), m_buttonCode(code) {}

    Input::InputCode m_buttonCode;
  };


  class POSITRON_API MouseDownEvent : public MouseButtonEvent {

    public:
    MouseDownEvent(Input::InputCode code, Point2D point) : MouseButtonEvent(code, point) {}

    inline std::string ToString() const override GET(F("MouseDownEvent: button {}, point {}", m_buttonCode, m_Point));

    EVENT_CLASS_TYPE(EventType::MouseButtonDown)
  };


  class POSITRON_API MouseUpEvent : public MouseButtonEvent {

    public:
    MouseUpEvent(Input::InputCode code, Point2D point) : MouseButtonEvent(code, point) {}

    inline std::string ToString() const override GET(F("MouseUpEvent: button {}, point {}", m_buttonCode, m_Point));

    EVENT_CLASS_TYPE(EventType::MouseButtonUp)
  };


  class POSITRON_API MouseMovedEvent : public MouseEvent {

    public:
    MouseMovedEvent(Point2D point) : MouseEvent(point) {}

    inline std::string ToString() const override GET(F("MouseMovedEvent: point {}", m_Point));

    EVENT_CLASS_TYPE(EventType::MouseMoved)
  };

  class POSITRON_API MouseScrolledEvent : public MouseEvent {

    public:
    MouseScrolledEvent(Vector2D offset, Point2D point) : MouseEvent(point), m_Offset(offset) {}

    inline std::string ToString() const override GET(F("MouseScrolledEvent: offset {}, point {}", m_Offset, m_Point));

    inline Vector2D GetOffset() const GET(m_Offset);

    EVENT_CLASS_TYPE(EventType::MouseScrolled)

    private:
    Vector2D m_Offset;
  };
}