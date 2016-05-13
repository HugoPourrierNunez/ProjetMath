#include "CCube.h"

CCube::CCube(double dWidth, double dHeight)
{
    m_dWidth = dWidth / 2;
    m_dHeight = dHeight / 2;
}

CCube::~CCube()
{
    //dtor
}

void CCube::DrawCube()
{
    float fFlotte = 10;
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, SOIL_load_OGL_texture("img/greybricktiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    // Front
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-m_dWidth, -m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(0.0f, 50.0f);
        glVertex3f(-m_dWidth, m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(50.0f, 50.0f);
        glVertex3f(m_dWidth, m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(50.0f, 0.0f);
        glVertex3f(m_dWidth, -m_dHeight + fFlotte, m_dWidth);

    // Left
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-m_dWidth, m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(0.0f, 50.0f);
        glVertex3f(-m_dWidth, -m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(50.0f, 50.0f);
        glVertex3f(-m_dWidth, -m_dHeight + fFlotte, -m_dWidth);
        glTexCoord2f(50.0f, 0.0f);
        glVertex3f(-m_dWidth, m_dHeight + fFlotte, -m_dWidth);

    // Back
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(m_dWidth, -m_dHeight + fFlotte, -m_dWidth);
        glTexCoord2f(0.0f, 50.0f);
        glVertex3f(m_dWidth, m_dHeight + fFlotte, -m_dWidth);
        glTexCoord2f(50.0f, 50.0f);
        glVertex3f(-m_dWidth, m_dHeight + fFlotte, -m_dWidth);
        glTexCoord2f(50.0f, 0.0f);
        glVertex3f(-m_dWidth, -m_dHeight + fFlotte, -m_dWidth);

    // Right
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(m_dWidth, m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(0.0f, 50.0f);
        glVertex3f(m_dWidth, -m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(50.0f, 50.0f);
        glVertex3f(m_dWidth, -m_dHeight + fFlotte, -m_dWidth);
        glTexCoord2f(50.0f, 0.0f);
        glVertex3f(m_dWidth, m_dHeight + fFlotte, -m_dWidth);

    // Bottom
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-m_dWidth, -m_dHeight + fFlotte, -m_dWidth);
        glTexCoord2f(0.0f, 50.0f);
        glVertex3f(-m_dWidth, -m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(50.0f, 50.0f);
        glVertex3f(m_dWidth, -m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(50.0f, 0.0f);
        glVertex3f(m_dWidth, -m_dHeight + fFlotte, -m_dWidth);

    // Top
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-m_dWidth, m_dHeight + fFlotte, m_dWidth);
        glTexCoord2f(0.0f, 50.0f);
        glVertex3f(-m_dWidth, m_dHeight + fFlotte, -m_dWidth);
        glTexCoord2f(50.0f, 50.0f);
        glVertex3f(m_dWidth, m_dHeight + fFlotte, -m_dWidth);
        glTexCoord2f(50.0f, 0.0f);
        glVertex3f(m_dWidth, m_dHeight + fFlotte, m_dWidth);
    glEnd();
}
