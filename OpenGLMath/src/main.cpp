#include "SceneOpenGL.h"

using namespace std;


int main(int argc, char **argv)
{
    SceneOpenGl scene("Test",800,600);

    bool result = scene.initWindow();
    if(result<0)
        return result;
    result = scene.initGL();
    if(result<0)
        return result;

    scene.mainLoop();


    return 0;
}
