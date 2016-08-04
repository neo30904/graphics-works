/****************************************************************************
Created By @ Ajay Singh Tanwar
-noobAdda
****************************************************************************/
#pragma once

#include <string>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>


namespace enginecore
{
    namespace graphics
    {
        class Window
        {
            public:
                Window():height_(0) , width_(0) , title_("Window")
                {

                }

                Window(int width , int height , std::string title);

                ~Window();

                void Update();
                bool Closed();
                void Clear();

            private :

                bool Init();

                int height_;
                int width_;
                std::string title_;
                GLFWwindow * window_;

                //static methods for callbacks
                static void KeyCallBack(GLFWwindow * window , int key , int scancode , int action , int mode);

        };
    }
}
