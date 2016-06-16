#ifndef DEFINE_PLANE
#define DEFINE_PLANE

#include "Shader.h"
#include "Texture.h"
#include "CVecteur.h"
#include "SquareMatrice.h"

class Plane
{
    public:
        Plane(float sizePlane, CVecteur *color);
        ~Plane();
        void draw( SquareMatrice* modelview, SquareMatrice* projection,Shader shader);
        void draw( SquareMatrice* modelview, SquareMatrice* projection,Shader shader, Texture *texture);

    private:
        float m_vertices[18];
        float m_colors[18];
        float m_textCoord[12];
};

#endif // CVECTEUR_H
