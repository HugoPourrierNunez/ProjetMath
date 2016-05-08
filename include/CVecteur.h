#ifndef CVECTEUR_H
#define CVECTEUR_H

#include <math.h>
class CVecteur
{
    public:
        CVecteur(int x, int y, int z);
        virtual ~CVecteur();
        int GetX();
        int GetY();
        int GetZ();
        static CVecteur* AdditionVecteur(CVecteur* v1, CVecteur* v2);
    protected:
    private:
        int m_iX;
        int m_iY;
        int m_iZ;
};

#endif // CVECTEUR_H
