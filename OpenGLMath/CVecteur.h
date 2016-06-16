#ifndef CVECTEUR_H
#define CVECTEUR_H

#include <math.h>
class CVecteur
{
    public:
        CVecteur(float x, float y, float z);
        virtual ~CVecteur();
        float getX();
        float getY();
        float getZ();
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        static CVecteur* AdditionVecteur(CVecteur* v1, CVecteur* v2);
    protected:
    private:
        float m_dX;
        float m_dY;
        float m_dZ;
};

#endif // CVECTEUR_H
