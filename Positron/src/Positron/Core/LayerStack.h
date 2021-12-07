#pragma once

#include "pch.h"
#include <Positron/Core/Layer.h>

namespace Positron {

  class POSITRON_API LayerStack {
    public:
    LayerStack() : m_Layers() {}
    ~LayerStack() = default;

    void PushFront(std::shared_ptr<Layer> layer);
    void PushBack(std::shared_ptr<Layer> layer);
    std::shared_ptr<Layer> PopFront();
    std::shared_ptr<Layer> PopBack();

    std::deque<std::shared_ptr<Layer>>::const_iterator begin() GET(m_Layers.begin());
    std::deque<std::shared_ptr<Layer>>::const_iterator end() GET(m_Layers.end());
    std::deque<std::shared_ptr<Layer>>::const_reverse_iterator rbegin() GET(m_Layers.rbegin());
    std::deque<std::shared_ptr<Layer>>::const_reverse_iterator rend() GET(m_Layers.rend());


    private:
    std::deque<std::shared_ptr<Layer>> m_Layers;
  };

}