#include "Cube.h"

using namespace std;

Cube::Cube(float cubeSize)
{
    float vertices[] = {-cubeSize, -cubeSize, -cubeSize,   cubeSize, -cubeSize, -cubeSize,   cubeSize, cubeSize, -cubeSize,     // Face 1
                    -cubeSize, -cubeSize, -cubeSize,   -cubeSize, cubeSize, -cubeSize,   cubeSize, cubeSize, -cubeSize,     // Face 1

                    cubeSize, -cubeSize, cubeSize,   cubeSize, -cubeSize, -cubeSize,   cubeSize, cubeSize, -cubeSize,       // Face 2
                    cubeSize, -cubeSize, cubeSize,   cubeSize, cubeSize, cubeSize,   cubeSize, cubeSize, -cubeSize,         // Face 2

                    -cubeSize, -cubeSize, cubeSize,   cubeSize, -cubeSize, cubeSize,   cubeSize, -cubeSize, -cubeSize,      // Face 3
                    -cubeSize, -cubeSize, cubeSize,   -cubeSize, -cubeSize, -cubeSize,   cubeSize, -cubeSize, -cubeSize,    // Face 3

                    -cubeSize, -cubeSize, cubeSize,   cubeSize, -cubeSize, cubeSize,   cubeSize, cubeSize, cubeSize,        // Face 4
                    -cubeSize, -cubeSize, cubeSize,   -cubeSize, cubeSize, cubeSize,   cubeSize, cubeSize, cubeSize,        // Face 4

                    -cubeSize, -cubeSize, -cubeSize,   -cubeSize, -cubeSize, cubeSize,   -cubeSize, cubeSize, cubeSize,     // Face 5
                    -cubeSize, -cubeSize, -cubeSize,   -cubeSize, cubeSize, -cubeSize,   -cubeSize, cubeSize, cubeSize,     // Face 5

                    -cubeSize, cubeSize, cubeSize,   cubeSize, cubeSize, cubeSize,   cubeSize, cubeSize, -cubeSize,         // Face 6
                    -cubeSize, cubeSize, cubeSize,   -cubeSize, cubeSize, -cubeSize,   cubeSize, cubeSize, -cubeSize};

    float colors[] = {1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 1
                    1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 1

                    0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 2
                    0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 2

                    0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,           // Face 3
                    0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,           // Face 3

                    1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 4
                    1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 4

                    0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 5
                    0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 5

                    0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,           // Face 6
                    0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0};          // Face 6

    float textCoord[] = {0, 0,   1, 0,   1, 1,     // Face 1
                           0, 0,   0, 1,   1, 1,     // Face 1

                           0, 0,   1, 0,   1, 1,     // Face 2
                           0, 0,   0, 1,   1, 1,     // Face 2

                           0, 0,   1, 0,   1, 1,     // Face 3
                           0, 0,   0, 1,   1, 1,     // Face 3

                           0, 0,   1, 0,   1, 1,     // Face 4
                           0, 0,   0, 1,   1, 1,     // Face 4

                           0, 0,   1, 0,   1, 1,     // Face 5
                           0, 0,   0, 1,   1, 1,     // Face 5

                           0, 0,   1, 0,   1, 1,     // Face 6
                           0, 0,   0, 1,   1, 1};    // Face 6


    for(int i=0;i<108;i++)
    {
        m_vertices[i]=vertices[i];
        m_colors[i]=colors[i];
        m_textCoord[i]=textCoord[i];
    }
}

Cube::~Cube(){}

void Cube::draw( SquareMatrice* modelview, SquareMatrice* projection,Shader shader, Texture *texture)
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

    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindTexture(GL_TEXTURE_2D, 0);
    // On désactive les tableaux Vertex Attrib puisque l'on n'en a plus besoin

    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(0);

    // On n'utilise plus le shader

    glUseProgram(0);
}

void Cube::draw( SquareMatrice* modelview, SquareMatrice* projection,Shader shader)
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

    glDrawArrays(GL_TRIANGLES, 0, 36);


    // On désactive les tableaux Vertex Attrib puisque l'on n'en a plus besoin

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    // On n'utilise plus le shader

    glUseProgram(0);
}
