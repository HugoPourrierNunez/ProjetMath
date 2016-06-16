#ifndef DEFINE_SPHERE
#define DEFINE_SPHERE

#include "Texture.h"
#include "SquareMatrice.h"
#include "Shader.h"

class Sphere
{
    public:
        static void draw(float radius, float xDivision, float yDivision,SquareMatrice *projection, SquareMatrice *modelview, Shader shader, Texture *texture);

};

#endif // DEFINE_SPHERE
