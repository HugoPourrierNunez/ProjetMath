#include "Texture.h"

using namespace std;

Texture::Texture(string file):m_imageFile(file)
{
}

Texture::~Texture()
{

}

bool Texture::load()
{
//Li le fichier
    SDL_Surface *img = IMG_Load(m_imageFile.c_str());
    if(img==0)
    {
        cout<<"Error : "<<SDL_GetError()<<endl;
        return false ;
    }
    //Génère la texture
    glGenTextures(1,&m_id);
    //Verouille pour modifer
    glBindTexture(GL_TEXTURE_2D, m_id);

    GLenum internalFormat(0);
    GLenum format(0);
    if(img->format->BytesPerPixel==3)
    {
        internalFormat=GL_RGB;
        if(img->format->Rmask==0xff)
        {
            format=GL_RGB;
        }
        else
        {
            format=GL_BGR;
        }
    }
    else if(img->format->BytesPerPixel==4)
    {
        internalFormat=GL_RGBA;
        if(img->format->Rmask==0xff)
        {
            format=GL_RGBA;
        }
        else
        {
            format=GL_BGRA;
        }
    }
    else
    {
        cout<<"Erreur mauvais format d'image"<<endl;
        SDL_FreeSurface(img);
        return false;
    }

    // Inversion de l'image

    SDL_Surface *revertImage = revertPixels(img);
    SDL_FreeSurface(img);

    glTexImage2D(GL_TEXTURE_2D,0,internalFormat,revertImage->w,revertImage->h,0,format,GL_UNSIGNED_BYTE,revertImage->pixels);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    //Déverouille
    glBindTexture(GL_TEXTURE_2D, 0);

    SDL_FreeSurface(revertImage);
    return true;
}


GLuint Texture::getId()
{
    return m_id;
}

void Texture::setImageFile(string file)
{
    m_imageFile=file;
}

SDL_Surface* Texture::revertPixels(SDL_Surface *sourceImage) const
{
    // Copie conforme de l'image source sans les pixels

    SDL_Surface *revertImg = SDL_CreateRGBSurface(0, sourceImage->w, sourceImage->h, sourceImage->format->BitsPerPixel, sourceImage->format->Rmask,
                                                         sourceImage->format->Gmask, sourceImage->format->Bmask, sourceImage->format->Amask);


    unsigned char* sourcePixels = (unsigned char*) sourceImage->pixels;
    unsigned char* invertPixels = (unsigned char*) revertImg->pixels;
    int h=revertImg->h, w=revertImg->w*sourceImage->format->BytesPerPixel;

    // Inversion des pixels

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
            invertPixels[(w * (h - 1 - i)) + j] = sourcePixels[(w * i) + j];
    }

    return revertImg;
}
