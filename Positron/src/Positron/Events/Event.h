#pragma once

#include "Positron/Core.h"

namespace Positron {

  enum class EventType {
    None = 0,
    AppTick, AppUpdate, AppRender,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    KeyDown, KeyUp,
    MouseButtonDown, MouseButtonUp, MouseMoved, MouseScrolled
  };

  enum EventCategory {
    None = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryWindow = BIT(1),
    EventCategoryInput = BIT(2),
    EventCategoryKeyboard = BIT(3),
    EventCategoryMouse = BIT(4),
    EventCategoryMouseButton = BIT(5),
  };

  #define EVENT_CLASS_TYPE(type)\
                static EventType GetStaticType() { return type; }\
                virtual EventType GetEventType() const override { return GetStaticType(); }\
                virtual const char* GetName() const override { return #type; }

  #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

  class POSITRON_API Event {

    public:
    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual std::string ToString() const { return GetName(); }

    inline bool IsInCategory(EventCategory category) {
      return GetCategoryFlags() & category;
    }

    protected:
    bool m_Handled = false;
  };

  class EventDispatcher {

    public:
    EventDispatcher(Event& event) : m_Event(event) {}

    template<typename T, typename F>
    bool Dispatch(const F& func) {
      if(m_Event.GetEventType() == T::GetEventType()) {
        m_Event.m_Handled |= func(static_cast<T&>(m_Event));
        return true;
      }
      return false;
    }

    private:
    Event& m_Event;
  };

  inline std::ostream& operator<<(std::ostream& os, const Event& e) {
    return os << e.ToString();
  }
}