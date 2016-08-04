/****************************************************************************
Created By @ Ajay Singh Tanwar
-EngineDevelopment
****************************************************************************/
#ifndef SHADER_H
#define SHADER_H

#pragma once

#include<iostream>
#include<GL/glew.h>

namespace enginecore
{
    namespace graphics
    {
        class Shader
        {
            public:
                Shader(std::string vertex_shader_path  , std::string fragment_shader_path);
                virtual ~Shader();

                void Enable();
                void Disable();
            protected:
            private:

                GLuint LoadShaders(std::string vertex_shader_path  , std::string fragment_shader_path);
                bool CheckIfCompiledSuccessfully(GLuint shader , bool is_shader);

                GLuint shader_program_id_;
        };
    }
}
#endif // SHADER_H
