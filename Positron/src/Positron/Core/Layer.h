#pragma once
#include "pch.h"
#include <Positron/Core/Core.h>
#include <Positron/Events/Event.h>

namespace Positron {
  class POSITRON_API Layer {
    public:
    Layer(const std::string& name = "Layer") : m_Name(name) {}
    virtual ~Layer() = default;

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnRender() {}
    virtual void OnEvent(Event& event) {}

    inline const std::string& GetName() const GET(m_Name);

    protected:
    std::string m_Name;
  };
}
