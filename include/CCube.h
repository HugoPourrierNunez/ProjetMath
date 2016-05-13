#ifndef CCUBE_H
#define CCUBE_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "SOIL.h"
class CCube
{
    public:
        CCube(double dWidth, double dHeight);
        virtual ~CCube();
        void DrawCube();
    protected:
    private:
        double m_dWidth;
        double m_dHeight;
};

#endif // CCUBE_H
