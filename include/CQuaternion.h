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
        CQuaternion(double angleDegree, CVecteur* pVecteur);
        virtual ~CQuaternion();
        CMatrice* QuaternionToMatrice();
        CQuaternion* MatriceToQuaternion();
        CQuaternion* QuaternionMultiplication(CQuaternion* q1, CQuaternion* q2);
        CQuaternion* ConjugueQuaternion();
        CQuaternion* AdditionQuaternion(CQuaternion* q1, CQuaternion* q2);
        double NormeQuaternion();

        double GetX();
        double GetY();
        double GetZ();
        double GetW();

        void SetX(double i);
        void SetY(double i);
        void SetZ(double i);
        void SetW(double i);

    protected:
    private:
        double m_dX;
        double m_dY;
        double m_dZ;
        double m_dW;
};

#endif // CQUATERNION_H
