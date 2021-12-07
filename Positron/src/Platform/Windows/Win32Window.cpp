#include "pch.h"
#include "Positron/Core/Log.h"
#include "Win32Window.h"
#include <Positron/Events/WindowEvent.h>
#include <Positron/Events/KeyboardEvent.h>
#include <Positron/Events/MouseEvent.h>

namespace Positron {

  static bool s_GLFWInitialized = false;
  static std::map<int, int> s_KeyPressed;

  static void GLFWErrorCallback(int error, const char* description) {
    CORE_ERROR("GLFW Error [{}]: {}", error, description);
  }

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
      // Initializing GLFW
      int result = glfwInit();
      CORE_ASSERT(result, "Error: could not initialize GLFW!");
      glfwSetErrorCallback(GLFWErrorCallback);
      s_GLFWInitialized = true;
    }

    m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), nullptr, nullptr);
    // Creating a GLFW Context
    glfwMakeContextCurrent(m_Window);

    // Initializing Glad Loader
    int result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    CORE_ASSERT(ret, "Failed to initialize Glad!");

    // Linking GLFW Window to m_Data
    glfwSetWindowUserPointer(m_Window, &m_Data);
    SetVSync(true);

    //Setting Window events callbacks

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      WindowCloseEvent event;
      data.EventCallback(event);
    });

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      data.width = width;
      data.height = height;

      WindowResizeEvent event(width, height);
      data.EventCallback(event);
    });

    glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      if(focused) {
        WindowFocusedEvent event;
        data.EventCallback(event);
      }
      else {
        WindowLostFocusEvent event;
        data.EventCallback(event);
      }
    });

    glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      WindowMovedEvent event(xpos, ypos);
      data.EventCallback(event);
    });

    glfwSetWindowRefreshCallback(m_Window, [](GLFWwindow* window) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      WindowRefreshedEvent event;
      data.EventCallback(event);
    });

    glfwSetWindowIconifyCallback(m_Window, [](GLFWwindow* window, int iconified) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      if(iconified) {
        WindowIconifiedEvent event;
        data.EventCallback(event);
      }
      else {
        WindowUniconifiedEvent event;
        data.EventCallback(event);
      }
    });

    glfwSetWindowMaximizeCallback(m_Window, [](GLFWwindow* window, int maximized) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      if(maximized) {
        WindowMaximizedEvent event;
        data.EventCallback(event);
      }
      else {
        WindowUnmaximizedEvent event;
        data.EventCallback(event);
      }
    });

    glfwSetWindowContentScaleCallback(m_Window, [](GLFWwindow* window, float xscale, float yscale) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      WindowContentScaledEvent event(xscale, yscale);
      data.EventCallback(event);
    });

    // Setting keyboard callback
    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

      switch(action) {
        case GLFW_PRESS:
        {
          s_KeyPressed[key] = 1;
          KeyDownEvent event(key, 1);
          data.EventCallback(event);
          break;
        }
        case GLFW_RELEASE:
        {
          KeyUpEvent event(key, s_KeyPressed[key]);
          s_KeyPressed[key] = 0;
          data.EventCallback(event);
          break;
        }
        case GLFW_REPEAT:
        {
          s_KeyPressed[key] += 1;
          KeyDownEvent event(key, s_KeyPressed[key]);
          data.EventCallback(event);
          break;
        }
      }
    });

    // TODO
    // glfwSetCharCallback
    // glfwSetCharModsCallback

    // Setting mouse callbacks
    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

      // Getting cursor position
      double xpos, ypos;
      glfwGetCursorPos(window, &xpos, &ypos);

      switch(action) {
        case GLFW_PRESS:
        {
          MouseDownEvent event(button, xpos, ypos);
          data.EventCallback(event);
          break;
        }
        case GLFW_RELEASE:
        {
          MouseUpEvent event(button, xpos, ypos);
          data.EventCallback(event);
          break;
        }
      }
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

      // Getting cursor position
      double xpos, ypos;
      glfwGetCursorPos(window, &xpos, &ypos);

      MouseScrolledEvent event(xoffset, yoffset, xpos, ypos);
      data.EventCallback(event);
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
      WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
      MouseMovedEvent event(xpos, ypos);
      data.EventCallback(event);
    });
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