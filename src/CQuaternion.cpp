#include "CQuaternion.h"

CQuaternion::CQuaternion(double angleDegree, CVecteur* pVecteur)
{

    double degRadian;
    degRadian =  angleDegree * M_PI / 180.0;

    m_dX = cos(degRadian/2);
    m_dY = pVecteur->GetX() * sin(degRadian/2);
    m_dZ = pVecteur->GetY() * sin(degRadian/2);
    m_dW = pVecteur->GetZ() * sin(degRadian/2);
}

CQuaternion::~CQuaternion()
{

}

// Début accesseurs
double CQuaternion::GetX()
{
    return m_dX;
}

double CQuaternion::GetY()
{
    return m_dY;
}

double CQuaternion::GetZ()
{
    return m_dZ;
}

double CQuaternion::GetW()
{
    return m_dW;
}

void CQuaternion::SetX(double i)
{
    m_dX = i;
}

void CQuaternion::SetY(double i)
{
    m_dY = i;
}

void CQuaternion::SetZ(double i)
{
    m_dZ = i;
}

void CQuaternion::SetW(double i)
{
    m_dW = i;
}
// Fin accesseurs

/*

1 - 2*qy2 - 2*qz2	2*qx*qy - 2*qz*qw	2*qx*qz + 2*qy*qw
2*qx*qy + 2*qz*qw	1 - 2*qx2 - 2*qz2	2*qy*qz - 2*qx*qw
2*qx*qz - 2*qy*qw	2*qy*qz + 2*qx*qw	1 - 2*qx2 - 2*qy2

*/
CMatrice* CQuaternion::QuaternionToMatrice()
{
    CMatrice* matriceResultat = NULL;

    double x1y1 = (1 - 2 * (this->m_dY * this->m_dY)) - (2 * (this->m_dZ * this->m_dZ));
    double x1y2 = (2 * this->m_dY * this->m_dX) - (2 * this->m_dZ * this->m_dW);
    double x1y3 = (2 * this->m_dZ * this->m_dX) + (2 * this->m_dY * this->m_dW);

    double x2y1 = (2 * this->m_dY * this->m_dX) + (2 * this->m_dZ * this->m_dW);
    double x2y2 = (1 - 2 * (this->m_dX * this->m_dX)) - (2 * (this->m_dZ * this->m_dZ));
    double x2y3 = (2 * this->m_dY * this->m_dZ) - (2 * this->m_dX * this->m_dW);

    double x3y1 = (2 * this->m_dZ * this->m_dX) - (2 * this->m_dY * this->m_dW);
    double x3y2 = (2 * this->m_dY * this->m_dZ) + (2 * this->m_dX * this->m_dW);
    double x3y3 = (1 - 2 * (this->m_dX * this->m_dX)) - (2 * (this->m_dY * this->m_dY));;

    matriceResultat = new CMatrice(x1y1,x1y2,x1y3,
                               x2y1,x2y2,x2y3,
                               x3y1,x3y2,x3y3);
    return matriceResultat;
}

CQuaternion* CQuaternion::MatriceToQuaternion()
{
    return NULL;
}

// Q*Q’=aa’-bb’-cc’-dd’+(ab’+ba’+cd’-dc’)i+(ac’+ca’+db’-bd’)j+(ad’+da’+bc’-cb’)k
CQuaternion* CQuaternion::QuaternionMultiplication(CQuaternion* q1, CQuaternion* q2)
{
    if(q1 == NULL || q2 == NULL)
        return NULL;

    CQuaternion* qResultat = new CQuaternion(0, new CVecteur(0,0,0));

    qResultat->SetX((q1->GetX() * q2->GetX()) - (q1->GetY() * q2->GetY()) - (q1->GetZ() * q2->GetZ()) - (q1->GetW() * q2->GetW()));
    qResultat->SetY((q1->GetX() * q2->GetY()) + (q1->GetY() * q2->GetX()) + (q1->GetZ() * q2->GetW()) - (q1->GetW() * q2->GetZ()));
    qResultat->SetZ((q1->GetX() * q2->GetZ()) + (q1->GetZ() * q2->GetZ()) + (q1->GetW() * q2->GetY()) - (q1->GetY() * q2->GetW()));
    qResultat->SetW((q1->GetX() * q2->GetW()) + (q1->GetW() * q2->GetX()) + (q1->GetY() * q2->GetZ()) - (q1->GetZ() * q2->GetY()));

    return qResultat;
}

CQuaternion* CQuaternion::ConjugueQuaternion()
{
    CQuaternion* pConjugue = new CQuaternion(m_dX, new CVecteur(-m_dY, -m_dZ, -m_dW));

    return pConjugue;
}

double CQuaternion::NormeQuaternion()
{
    return sqrt( m_dW * m_dW + m_dX * m_dX + m_dY * m_dY + m_dZ * m_dZ);
}

CQuaternion* CQuaternion::AdditionQuaternion(CQuaternion* q1, CQuaternion* q2)
{
    if(q1 == NULL || q2 == NULL)
        return NULL;

    CVecteur* pV1 = new CVecteur(q1->GetY(), q1->GetZ(), q1->GetW());
    CVecteur* pV2 = new CVecteur(q2->GetY(), q2->GetZ(), q2->GetW());

    CVecteur* pV3 = pV1->AdditionVecteur(pV1, pV2);

    CQuaternion* qResultat = new CQuaternion(q1->GetX() + q2->GetX(), new CVecteur(pV3->GetX(), pV3->GetY(), pV3->GetZ()));

    return qResultat;
}
