#include "CMatrice.h"

CMatrice::CMatrice(int x1y1, int x1y2, int x1y3, int x2y1, int x2y2, int x2y3, int x3y1, int x3y2, int x3y3)
{
    m_matrice[0][0] = x1y1;
    m_matrice[0][1] = x1y2;
    m_matrice[0][2] = x1y3;

    m_matrice[1][0] = x2y1;
    m_matrice[1][1] = x2y2;
    m_matrice[1][2] = x2y3;

    m_matrice[2][0] = x3y1;
    m_matrice[2][1] = x3y2;
    m_matrice[2][2] = x3y3;
}

CMatrice::CMatrice()
{
    m_matrice[0][0] = 0;
    m_matrice[0][1] = 0;
    m_matrice[0][2] = 0;

    m_matrice[1][0] = 0;
    m_matrice[1][1] = 0;
    m_matrice[1][2] = 0;

    m_matrice[2][0] = 0;
    m_matrice[2][1] = 0;
    m_matrice[2][2] = 0;
}


CMatrice::~CMatrice()
{

}
