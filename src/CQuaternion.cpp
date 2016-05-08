#include "CQuaternion.h"

CQuaternion::CQuaternion(int x, int y, int z, int w)
{
    m_iX = x;
    m_iY = y;
    m_iZ = z;
    m_iW = w;
    m_qI = NULL;
    m_qJ = NULL;
    m_qK = NULL;
}

CQuaternion::~CQuaternion()
{

}

// Début accesseurs
int CQuaternion::GetX()
{
    return m_iX;
}

int CQuaternion::GetY()
{
    return m_iY;
}

int CQuaternion::GetZ()
{
    return m_iZ;
}

int CQuaternion::GetW()
{
    return m_iW;
}

void CQuaternion::SetX(int i)
{
    m_iX = i;
}

void CQuaternion::SetY(int i)
{
    m_iY = i;
}

void CQuaternion::SetZ(int i)
{
    m_iZ = i;
}

void CQuaternion::SetW(int i)
{
    m_iW = i;
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

    int x1y1 = (1 - 2 * sqrt(this->m_iY)) - (2 * sqrt(this->m_iZ));
    int x1y2 = 0;
    int x1y3 = 0;

    int x2y1 = 0;
    int x2y2 = 0;
    int x2y3 = 0;

    int x3y1 = 0;
    int x3y2 = 0;
    int x3y3 = 0;

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

    m_qI = new CQuaternion(0, 1, 0, 0);
    m_qJ = new CQuaternion(0, 0, 1, 0);
    m_qK = new CQuaternion(0, 0, 0, 1);

    CQuaternion* qResultat = new CQuaternion(0,0,0,0);

    qResultat->SetX((q1->GetX() * q2->GetX()) - (q1->GetY() * q2->GetY()) - (q1->GetZ() * q2->GetZ()) - (q1->GetW() * q2->GetW()));
    qResultat->SetY((q1->GetX() * q2->GetY()) + (q1->GetY() * q2->GetX()) + (q1->GetZ() * q2->GetW()) - (q1->GetW() * q2->GetZ()));
    qResultat->SetZ((q1->GetX() * q2->GetZ()) + (q1->GetZ() * q2->GetZ()) + (q1->GetW() * q2->GetY()) - (q1->GetY() * q2->GetW()));
    qResultat->SetW((q1->GetX() * q2->GetW()) + (q1->GetW() * q2->GetX()) + (q1->GetY() * q2->GetZ()) - (q1->GetZ() * q2->GetY()));

    return qResultat;
}

CQuaternion* CQuaternion::ConjugueQuaternion()
{
    CQuaternion* pConjugue = new CQuaternion(m_iX, -m_iY, -m_iZ, -m_iW);

    return pConjugue;
}

int CQuaternion::NormeQuaternion()
{
    return sqrt( m_iW * m_iW + m_iX * m_iX + m_iY * m_iY + m_iZ * m_iZ);
}

CQuaternion* CQuaternion::AdditionQuaternion(CQuaternion* q1, CQuaternion* q2)
{
    if(q1 == NULL || q2 == NULL)
        return NULL;

    CVecteur* pV1 = new CVecteur(q1->GetY(), q1->GetZ(), q1->GetW());
    CVecteur* pV2 = new CVecteur(q2->GetY(), q2->GetZ(), q2->GetW());

    CVecteur* pV3 = pV1->AdditionVecteur(pV1, pV2);

    CQuaternion* qResultat = new CQuaternion(q1->GetX() + q2->GetX(), pV3->GetX(), pV3->GetY(), pV3->GetZ());

    return qResultat;
}
