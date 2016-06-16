#include "SceneOpenGL.h"
#include "CVecteur.h"

using namespace std;


int main(int argc, char **argv)
{
    SceneOpenGl scene("Test",800,600);

    bool result = scene.initWindow();
    if(result<0)
        return result;
    result = scene.initGL();
    if(result<0)
        return result;

    scene.mainLoop();

//    SquareMatrice *m = new SquareMatrice(45,CVecteur(1,2,3));
//    CQuaternion *q = new CQuaternion(45, new CVecteur(1,2,3,true));
//
//    CVecteur *v = new CVecteur(1,2,3);
//    cout<<v->getNorme();
//    m->print();
//    cout<<endl;
//    m=q->QuaternionToMatrice();
//    m->print();

    return 0;
}
