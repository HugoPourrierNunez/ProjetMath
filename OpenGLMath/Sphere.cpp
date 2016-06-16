#include "Sphere.h"


 void Sphere::draw(float radius, float xDivision, float yDivision,SquareMatrice *projection, SquareMatrice *modelview, Shader shader, Texture *texture)
{

    glEnable(GL_TEXTURE_2D);

    glUseProgram(shader.getProgramID());
    glBindTexture(GL_TEXTURE_2D,texture->getId());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "modelview"), 1, GL_FALSE, modelview->get_ptr());
    glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "projection"), 1, GL_FALSE, projection->get_ptr());

    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);
    gluQuadricDrawStyle(params, GLU_FILL);
    gluQuadricNormals(params, GLU_SMOOTH);
    gluSphere(params,radius,xDivision,yDivision);

    gluDeleteQuadric(params);

    glBindTexture(GL_TEXTURE_2D,0);
    glUseProgram(0);
}
