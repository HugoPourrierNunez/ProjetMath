#include "CVecteur.h"

CVecteur::CVecteur(int x, int y, int z)
{
    m_iX = x;
    m_iY = y;
    m_iZ = z;
}

CVecteur::~CVecteur()
{

}

// Début accesseurs
int CVecteur::GetX()
{
    return m_iX;
}

int CVecteur::GetY()
{
    return m_iY;
}

int CVecteur::GetZ()
{
    return m_iZ;
}

// Fin accesseurs

CVecteur* CVecteur::AdditionVecteur(CVecteur* v1, CVecteur* v2)
{
    CVecteur* vecteurResultat = new CVecteur(v1->GetX() + v2->GetX(), v1->GetY() + v2->GetY(), v1->GetZ() + v2->GetZ());

    return vecteurResultat;
}




