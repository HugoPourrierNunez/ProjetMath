#include "CVecteur.h"

CVecteur::CVecteur(double x, double y, double z)
{
    m_dX = x;
    m_dY = y;
    m_dZ = z;
}

CVecteur::~CVecteur()
{

}

// Début accesseurs
double CVecteur::GetX()
{
    return m_dX;
}

double CVecteur::GetY()
{
    return m_dY;
}

double CVecteur::GetZ()
{
    return m_dZ;
}

// Fin accesseurs

CVecteur* CVecteur::AdditionVecteur(CVecteur* v1, CVecteur* v2)
{
    CVecteur* vecteurResultat = new CVecteur(v1->GetX() + v2->GetX(), v1->GetY() + v2->GetY(), v1->GetZ() + v2->GetZ());

    return vecteurResultat;
}




