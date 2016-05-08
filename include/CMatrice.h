#ifndef CMATRICE_H
#define CMATRICE_H

#include <math.h>
class CMatrice
{
    public:
        CMatrice(int x1y1, int x1y2, int x1y3, int x2y1, int x2y2, int x2y3, int x3y1, int x3y2, int x3y3);
        CMatrice();
        virtual ~CMatrice();
    protected:
    private:
        int m_matrice[3][3];
};

#endif // CMATRICE_H
