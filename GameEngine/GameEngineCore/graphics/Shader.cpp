/****************************************************************************
Created By @ Ajay Singh Tanwar
-EngineDevelopment
****************************************************************************/
#include "Shader.h"
#include "utils/Fileutils.h"
#include "include/macros.h"

namespace enginecore
{
    namespace graphics
    {

        Shader::Shader(std::string vertex_shader_path  , std::string fragment_shader_path)
        {
            //ctor
            shader_program_id_ =  LoadShaders(vertex_shader_path  , fragment_shader_path);
        }

        Shader::~Shader()
        {
            //dtor
        }

        GLuint Shader::LoadShaders(std::string vertex_shader_path  , std::string fragment_shader_path)
        {
            //Read String from shader files
            utils::Fileutils * filereader = new utils::Fileutils();

            std::string vertex_shader_string ;
            filereader->GetStringFromFile(vertex_shader_path , vertex_shader_string);
            const char * vertex_source = vertex_shader_string.c_str();

            std::string fragment_shader_string ;
            filereader->GetStringFromFile(fragment_shader_path , fragment_shader_string);
            const char * fragment_source = fragment_shader_string.c_str();

            //Create Vertex Shader
            GLuint vertex_shader ;
            vertex_shader = glCreateShader(GL_VERTEX_SHADER);

            //Attach the source to the shader
            glShaderSource(vertex_shader , 1 , &vertex_source,nullptr);
            //compile shader
            glCompileShader(vertex_shader);

            if(!CheckIfCompiledSuccessfully(vertex_shader , true))
            {
                return 0;
            }

            //Create Fragment Shader
            GLuint fragment_shader ;
            fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

            //Attach the source to the shader
            glShaderSource(fragment_shader , 1 , &fragment_source,nullptr);
            //compile shader
            glCompileShader(fragment_shader);

            //Create if shader compiled properly
            if(!CheckIfCompiledSuccessfully(fragment_shader , true))
            {
                return 0;
            }

            //Create Shader Program and link the compiled shaders
            GLuint shader_program;
            shader_program = glCreateProgram();

            //Attach shaders
            glAttachShader(shader_program , vertex_shader);
            glAttachShader(shader_program , fragment_shader);

            //Link Program
            glLinkProgram(shader_program);

            if(!CheckIfCompiledSuccessfully(shader_program , false))
            {
                return 0;
            }

            glUseProgram(shader_program);

            //Delete Shaders Objects
            glDeleteShader(vertex_shader);
            glDeleteShader(fragment_shader);

            return shader_program;
        }

        bool Shader::CheckIfCompiledSuccessfully(GLuint id , bool is_shader)
        {
            GLint success;
            GLchar log[512];

            glGetShaderiv(id , GL_COMPILE_STATUS , &success);

            if(!success)
            {
                glGetShaderInfoLog(id , 512 , nullptr , log);
                LOG("Shader Compiling failed %s " , log);
                if(is_shader)
                {
                    glDeleteShader(id);
                }
                return false;
            }

            return true;
        }

        void Shader::Enable()
        {
            glUseProgram(shader_program_id_);
        }

        void Shader::Disable()
        {
            glUseProgram(0);
        }
    }
}
