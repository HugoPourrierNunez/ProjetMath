#ifndef DEF_SCENEOPENGL
#define DEF_SCENEOPENGL

// Includes

#ifdef WIN32
#include <GL/glew.h>

#else
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>

#endif

// Includes GLM

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <SDL2/SDL.h>
#include <iostream>

#include <string>
#include "Shader.h"
#include "SquareMatrice.h"
#include "Cube.h"
#include "CQuaternion.h"
#include "Texture.h"
#include "Plane.h"
#include "math.h"
#include "Sphere.h"

class SceneOpenGl
{
public:
    SceneOpenGl(std::string titleWindow, int widthWindow, int heightWindow);
    ~SceneOpenGl();

    int initWindow();
    int initGL();
    void mainLoop();

private:
    std::string m_titleWindow;
    int m_widthWindow;
    int m_heightWindow;

    SDL_Window* m_window;
    SDL_GLContext m_contextOpenGl;
    SDL_Event m_events;

};
#endif
