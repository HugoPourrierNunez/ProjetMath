#ifndef DEF_CUBE
#define DEF_CUBE

#include "SquareMatrice.h"
#include "Shader.h"
#include "Texture.h"

class Cube
{
public:
    Cube(float cubeSize);
    ~Cube();
    void draw( SquareMatrice* modelview, SquareMatrice* projection,Shader shader);
    void draw( SquareMatrice* modelview, SquareMatrice* projection,Shader shader, Texture *texture);

private:
    float m_vertices[108];
    float m_colors[108];
    float m_textCoord[108];

};
#endif
