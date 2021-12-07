#include "pch.h"
#include "LayerStack.h"
namespace Positron {

  void LayerStack::PushFront(std::shared_ptr<Layer> layer) {
    m_Layers.push_front(layer);
    layer->OnAttach();
  }

  void LayerStack::PushBack(std::shared_ptr<Layer> layer) {
    m_Layers.push_back(layer);
    layer->OnAttach();
  }

  std::shared_ptr<Layer> LayerStack::PopFront() {
    std::shared_ptr<Layer> front = m_Layers.front();
    m_Layers.pop_front();
    front->OnDetach();
    return front;
  }

  std::shared_ptr<Layer> LayerStack::PopBack() {
    std::shared_ptr<Layer> back = m_Layers.back();
    m_Layers.pop_back();
    back->OnDetach();
    return back;
  }

}