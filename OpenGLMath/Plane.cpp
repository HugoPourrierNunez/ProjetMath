#include "Plane.h"

using namespace std;

Plane::Plane(float sizePlane, CVecteur *color)
{
    float vertices[] ={-sizePlane,0,-sizePlane,  +sizePlane,0,-sizePlane,  +sizePlane,0,+sizePlane,
                        -sizePlane,0,-sizePlane,  -sizePlane,0,+sizePlane, +sizePlane,0,+sizePlane};

    float colors[] = {color->getX(), color->getY(), color->getZ(),   color->getX(), color->getY(), color->getZ(),   color->getX(), color->getY(), color->getZ(),           // Face 1
                    color->getX(), color->getY(), color->getZ(),   color->getX(), color->getY(), color->getZ(),   color->getX(), color->getY(), color->getZ()};

    float textCoord[] = {0, 0,   sizePlane, 0,   sizePlane, sizePlane,     // Face 1
                           0, 0,   0, sizePlane,   sizePlane, sizePlane};


    for(int i=0;i<18;i++)
    {
        m_vertices[i]=vertices[i];
        m_colors[i]=colors[i];
    }
    for(int i=0;i<12;i++)
        m_textCoord[i]=textCoord[i];
}

Plane::~Plane(){}

void Plane::draw( SquareMatrice* modelview, SquareMatrice* projection,Shader shader, Texture *texture)
{
    // On spécifie quel shader utiliser

    glUseProgram(shader.getProgramID());


    // On remplie puis on active le tableau Vertex Attrib 0

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
    glEnableVertexAttribArray(0);


    // Même chose avec le tableau Vertex Attrib 1

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, m_textCoord);
    glEnableVertexAttribArray(2);

    // On envoie les matrices au shader

    glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "modelview"), 1, GL_FALSE, modelview->get_ptr());
    glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "projection"), 1, GL_FALSE, projection->get_ptr());

    // On affiche le polygone
    glBindTexture(GL_TEXTURE_2D, texture->getId());

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindTexture(GL_TEXTURE_2D, 0);
    // On désactive les tableaux Vertex Attrib puisque l'on n'en a plus besoin

    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(0);

    // On n'utilise plus le shader

    glUseProgram(0);
}

void Plane::draw( SquareMatrice* modelview, SquareMatrice* projection,Shader shader)
{
    // On spécifie quel shader utiliser

    glUseProgram(shader.getProgramID());


    // On remplie puis on active le tableau Vertex Attrib 0

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
    glEnableVertexAttribArray(0);


    // Même chose avec le tableau Vertex Attrib 1

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, m_colors);
    glEnableVertexAttribArray(1);

    // On envoie les matrices au shader

    glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "modelview"), 1, GL_FALSE, modelview->get_ptr());
    glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "projection"), 1, GL_FALSE, projection->get_ptr());

    // On affiche le polygone

    glDrawArrays(GL_TRIANGLES, 0, 6);


    // On désactive les tableaux Vertex Attrib puisque l'on n'en a plus besoin

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    // On n'utilise plus le shader

    glUseProgram(0);
}
