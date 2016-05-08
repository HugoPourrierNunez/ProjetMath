#ifndef CQUATERNION_H
#define CQUATERNION_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "CMatrice.h"
#include "CVecteur.h"

class CQuaternion
{
    public:
        CQuaternion(int x, int y, int z, int w);
        virtual ~CQuaternion();
        CMatrice* QuaternionToMatrice();
        CQuaternion* MatriceToQuaternion();
        CQuaternion* QuaternionMultiplication(CQuaternion* q1, CQuaternion* q2);
        CQuaternion* ConjugueQuaternion();
        CQuaternion* AdditionQuaternion(CQuaternion* q1, CQuaternion* q2);
        int NormeQuaternion();

        int GetX();
        int GetY();
        int GetZ();
        int GetW();

        void SetX(int i);
        void SetY(int i);
        void SetZ(int i);
        void SetW(int i);

    protected:
    private:
        int m_iX;
        int m_iY;
        int m_iZ;
        int m_iW;

        CQuaternion* m_qI;
        CQuaternion* m_qJ;
        CQuaternion* m_qK;
};

#endif // CQUATERNION_H
