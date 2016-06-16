#include "SceneOpenGL.h"

using namespace std;
using namespace glm;

SceneOpenGl::SceneOpenGl(std::string titleWindow, int widthWindow, int heightWindow):
    m_titleWindow("Test"), m_widthWindow(widthWindow), m_heightWindow(heightWindow),
    m_window(0), m_contextOpenGl(0)
{

}

SceneOpenGl::~SceneOpenGl()
{
    SDL_GL_DeleteContext(m_contextOpenGl);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}


int SceneOpenGl::initWindow()
{
    // Initialisation de la SDL

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return -1;
    }

    //Version OpenGL

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);


    //Double Buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


    // Création de la fenêtre

    m_window = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_widthWindow, m_heightWindow, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);


    if(m_window==0)
    {
        cout<<"Erreur lors de la creation de la fenetre : " <<SDL_GetError() <<endl;
        SDL_Quit();
        return -1;
    }

    m_contextOpenGl = SDL_GL_CreateContext(m_window);

    if(m_contextOpenGl==0)
    {

        cout<<SDL_GetError()<<endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return -2;
    }

    return 0;
}


int SceneOpenGl::initGL()
{
    #ifdef WIN32

        GLenum initialisationGLEW( glewInit() );

        if(initialisationGLEW!=GLEW_OK)
        {

            cout<<"Erreur d'initialisation GLEW" <<glewGetErrorString(initialisationGLEW)<<endl;

            SDL_GL_DeleteContext(m_contextOpenGl);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return -3;
        }

    #endif // WIN32

    // Activation du Depth Buffer

    glEnable(GL_DEPTH_TEST);

    return 0;
}

void SceneOpenGl::mainLoop()
{
    //Variables
    int startLoop=0,endLoop=0, time=0, frameRate=1000/50;
    float speedCam = .2;
    bool terminer(false);
    bool isRotate=true;

    // Shader

    Shader shader("Shaders/texture.vert", "Shaders/texture.frag");
    shader.charger();


    CVecteur *posCube = new CVecteur(0,-2,0);
    Cube *cube = new Cube(2);

    Texture *caisse = new Texture("images/caisse.jpg");
    caisse->load();


    Texture *grass = new Texture("images/grass.jpg");
    grass->load();

    CVecteur *red = new CVecteur(1,0,0);
    CVecteur *posPlane = new CVecteur(0,0,0);

    Plane *plane = new Plane(10,red);

    // Matrices

    float angle=0;

    CVecteur *translateCam = new CVecteur(0,1,10);

    SquareMatrice *projection = new SquareMatrice(70,(float)m_widthWindow/m_heightWindow,1,100);
    SquareMatrice *camera = new SquareMatrice(translateCam,20,0);
    SquareMatrice *modelview = new SquareMatrice(4,true);

    SquareMatrice *rotation ;//= new SquareMatrice(angle,CVecteur(0,1,0));

    CQuaternion *quatRotation = new CQuaternion(angle,new CVecteur(0,1,0));
    rotation = quatRotation->QuaternionToMatrice();

    SquareMatrice *translate = new SquareMatrice(4,true);

    GLUquadric* quadrique;

    quadrique = gluNewQuadric();


//    gluSphere()

    // Boucle principale

    while(!terminer)
    {
        startLoop=SDL_GetTicks();
        // Gestion des évènements

        SDL_PollEvent(&m_events);

        if(m_events.window.event == SDL_WINDOWEVENT_CLOSE )
            terminer = true;
        if(m_events.type == SDL_KEYDOWN)
        {
            if(m_events.key.keysym.scancode == SDL_SCANCODE_SPACE)
                terminer = true;
            else if(m_events.key.keysym.scancode == SDL_SCANCODE_A)
            {
                translateCam->setX(translateCam->getX()+speedCam);
                camera->reinit(translateCam,20,0);
            }
            else if(m_events.key.keysym.scancode == SDL_SCANCODE_D)
            {
                translateCam->setX(translateCam->getX()-speedCam);
                camera->reinit(translateCam,20,0);
            }
            else if(m_events.key.keysym.scancode == SDL_SCANCODE_W)
            {
                translateCam->setZ(translateCam->getZ()+speedCam);
                camera->reinit(translateCam,20,0);
            }
            else if(m_events.key.keysym.scancode == SDL_SCANCODE_S)
            {
                translateCam->setZ(translateCam->getZ()-speedCam);
                camera->reinit(translateCam,20,0);
            }
        }

        // Nettoyage de l'écran

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        Dessin de tout ce qu'on veux

        modelview->reinit(true);
        translate->reinit(0,2,0,SquareMatrice::Translation);
        if(isRotate)
        {
            angle+=1;
            if(angle==360) angle=0;
//            rotation->reinit(angle,CVecteur(1,2,3,true));
            quatRotation->reinit(angle,new CVecteur(1,2,3,true));
            rotation = quatRotation->QuaternionToMatrice();
//            rotation->print();
            modelview->mult(rotation);
        }
        modelview->mult(translate);
        modelview->mult(camera);

        cube->draw(modelview,projection,shader,caisse);

        modelview->reinit(true);
        modelview->mult(camera);

        plane->draw(modelview,projection,shader,grass);

        //Mise à jour window
        SDL_GL_SwapWindow(m_window);

        endLoop=SDL_GetTicks();
        time=endLoop-startLoop;

        if(time <frameRate)
            SDL_Delay(frameRate-time);

    }
}
