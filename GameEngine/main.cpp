#include <iostream>

#include "graphics/Window.h"
#include "utils/Fileutils.h"
#include "graphics/Shader.h"
#include "include/macros.h"

using namespace enginecore;

int main()
{
    graphics::Window window(800 , 800, "Engine Development");

    //utils::Fileutils * file_utils = new utils::Fileutils();

    /*std::string shader_string;
    std::string filepath("GameEngineCore/shaders/99tlevel_98.json");
    file_utils->GetStringFromFile( filepath, shader_string);
    LOG("This is content of file : %s" , shader_string.c_str());
    */

    graphics::Shader shader_ref("GameEngineCore/shaders/basic.vert", "GameEngineCore/shaders/basic.frag");

    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f, // Left
         0.5f, -0.5f, 0.0f, // Right
         0.0f,  0.5f, 0.0f  // Top
    };


    GLuint vbo;
    GLuint vao;

    glGenVertexArrays(1, & vao);
    glGenBuffers(1,&vbo);

    //bind vao and then set vbo abd vertex attribs

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER , vbo);
    glBufferData(GL_ARRAY_BUFFER , sizeof(vertices) , vertices , GL_STATIC_DRAW);



    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    //the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Unbind VAO
    glBindVertexArray(0);

    while(!window.Closed())
    {
        window.Clear();
        //Draw Triangle
        shader_ref.Enable();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES , 0 , 3);
        glBindVertexArray(0);


        window.Update();
    }

    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    LOG("going haha");
    return 0;
}
