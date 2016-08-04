/****************************************************************************
Created By @ Ajay Singh Tanwar
-noobAdda
****************************************************************************/

#include "include/macros.h"
#include "Window.h"

namespace enginecore
{
    namespace graphics
    {
        Window::Window(int width , int height , std::string title)
        {
            width_ = width;
            height_ = height;
            title_ = title;

            window_ = nullptr;
            Init();
        }

        bool Window::Init()
        {
            /*
            *Initialize the GLFW
            */
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR , 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR , 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE , GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_RESIZABLE , GL_FALSE);

            window_ = glfwCreateWindow(width_ , height_, title_.c_str() , nullptr , nullptr);

            LOG("Created Window");
            LOG("Title : %s" , title_.c_str());
            LOG("Width :  %d , Height : %d", width_ , height_);

            if(!window_)
            {
                LOG("Window could not be created");
                glfwTerminate();
                return -1;
            }

            glfwMakeContextCurrent(window_);

            glewExperimental = GL_TRUE;

            if(glewInit() != GLEW_OK)
            {
                LOG("GLEW Could not be intialized");
                glfwTerminate();
                return false;
            }

            int width , height;

            glfwGetFramebufferSize(window_ ,&width , &height);
            glViewport(0 , 0 , width , height);

            glfwSetKeyCallback(window_ , Window::KeyCallBack);

            return true;
        }

        void Window::Update()
        {
            glfwPollEvents();
            glfwSwapBuffers(window_);
        }

        void Window::Clear()
        {
            glClearColor(0.3f,0.2f,0.3f,1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        bool Window::Closed()
        {
            return glfwWindowShouldClose(window_);
        }

        void Window::KeyCallBack(GLFWwindow * window , int key , int scancode , int action , int mode)
        {
            if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            {
                glfwSetWindowShouldClose(window , GL_TRUE);
            }
        }

        Window::~Window()
        {
            LOG("terminating");
            glfwTerminate();
        }
    }

}
