#pragma once

#include "Event.h"
#include <Positron/Core/InputCodes.h>

namespace Positron {

  class POSITRON_API KeyboardEvent : public Event {

    public:

    inline Input::InputCode GetKeyCode() const GET(m_KeyCode);

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

    protected:
    KeyboardEvent(Input::InputCode code) : m_KeyCode(code) {}

    Input::InputCode m_KeyCode;
  };

  class POSITRON_API KeyDownEvent : public KeyboardEvent {

    public:
    KeyDownEvent(Input::InputCode code, int repeatCount) :
      KeyboardEvent(code),
      m_RepeatCount(repeatCount) {}

    inline std::string ToString() const override GET(F("KeyDownEvent: key {} ({} repeats)", m_KeyCode, m_RepeatCount));

    inline int GetRepeatCount() const GET(m_RepeatCount);

    EVENT_CLASS_TYPE(EventType::KeyDown)

    private:
    int m_RepeatCount;
  };

  class POSITRON_API KeyUpEvent : public KeyboardEvent {

    public:
    KeyUpEvent(int keycode) : KeyboardEvent(keycode) {}

    inline std::string ToString() const override GET(F("KeyUpEvent: key {}", m_KeyCode));

    EVENT_CLASS_TYPE(EventType::KeyUp)
  };
}