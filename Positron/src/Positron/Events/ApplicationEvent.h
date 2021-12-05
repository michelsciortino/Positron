#pragma once

#include "Event.h"

namespace Positron {

  class POSITRON_API ApplicationEvent : public Event {
    public:

    inline virtual std::string ToString() const override GET("ApplicationEvent");

    EVENT_CLASS_CATEGORY(EventCategoryApplication)
  };


  class POSITRON_API AppUpdateEvent : public ApplicationEvent {
    public:
    AppUpdateEvent() {}

    inline std::string ToString() const override GET("AppUpdateEvent");

    EVENT_CLASS_TYPE(EventType::AppUpdate)
  };

  class POSITRON_API AppRenderEvent : public ApplicationEvent {
    public:
    AppRenderEvent() {}

    inline std::string ToString() const override GET("AppRenderEvent");

    EVENT_CLASS_TYPE(EventType::AppTick)
  };

  class POSITRON_API AppTickEvent : public ApplicationEvent {
    public:
    AppTickEvent() {}

    inline std::string ToString() const override GET("AppTickEvent");

    EVENT_CLASS_TYPE(EventType::AppTick)
  };
}
