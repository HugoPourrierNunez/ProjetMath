#ifndef CVECTEUR_H
#define CVECTEUR_H

#include <math.h>
class CVecteur
{
    public:
        CVecteur(double x, double y, double z);
        virtual ~CVecteur();
        double GetX();
        double GetY();
        double GetZ();
        static CVecteur* AdditionVecteur(CVecteur* v1, CVecteur* v2);
    protected:
    private:
        double m_dX;
        double m_dY;
        double m_dZ;
};

#endif // CVECTEUR_H
