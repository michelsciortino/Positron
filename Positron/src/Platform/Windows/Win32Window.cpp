#include "pch.h"
#include "Positron/Core/Log.h"
#include "Win32Window.h"

namespace Positron {

  static bool s_GLFWInitialized = false;

  Window* Window::Create(const WindowProps& props) {
    return new Win32Window(props);
  }

  Win32Window::Win32Window(const WindowProps& props) {
    Init(props);
  }

  Win32Window::~Win32Window() {
    Shutdown();
  }

  void Win32Window::Init(const WindowProps& props) {
    m_Data.title = props.title;
    m_Data.height = props.height;
    m_Data.width = props.width;

    CORE_INFO("Creating window {} ({}, {})", props.title, props.width, props.height);

    if(!s_GLFWInitialized) {
      int result = glfwInit();
      CORE_ASSERT(result, "Error: could not initialize GLFW!");
      s_GLFWInitialized = true;
    }

    m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, &m_Data);
    SetVSync(true);
  }

  void Win32Window::Shutdown() {
    CORE_INFO("Destroying window {})", m_Data.title);
    glfwDestroyWindow(m_Window);
  }

  void Win32Window::OnUpdate() {
    //Poll events
    glfwPollEvents();
    //Swap buffers
    glfwSwapBuffers(m_Window);
  }

  void Win32Window::SetVSync(bool enabled) {
    if(enabled)
      glfwSwapInterval(1);
    else
      glfwSwapInterval(0);
    m_Data.vSync = enabled;
  }

  bool Win32Window::IsVSync() const {
    return m_Data.vSync;
  }

}