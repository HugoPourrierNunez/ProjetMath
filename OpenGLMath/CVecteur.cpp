#include "CVecteur.h"

CVecteur::CVecteur(float x, float y, float z)
{
    m_dX = x;
    m_dY = y;
    m_dZ = z;
}

CVecteur::~CVecteur()
{

}

// Début accesseurs
float CVecteur::getX()
{
    return m_dX;
}

float CVecteur::getY()
{
    return m_dY;
}

float CVecteur::getZ()
{
    return m_dZ;
}

void CVecteur::setX(float x)
{
    m_dX=x;
}

void CVecteur::setY(float y)
{
    m_dY=y;
}

void CVecteur::setZ(float z)
{
    m_dZ=z;
}

// Fin accesseurs

CVecteur* CVecteur::AdditionVecteur(CVecteur* v1, CVecteur* v2)
{
    CVecteur* vecteurResultat = new CVecteur(v1->getX() + v2->getX(), v1->getY() + v2->getY(), v1->getZ() + v2->getZ());

    return vecteurResultat;
}




