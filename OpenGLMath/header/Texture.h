#ifndef DEFINE_TEXTURE
#define DEFINE_TEXTURE


#ifdef WIN32
#include <GL/glew.h>

#else
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>

#endif


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Texture
{
    public:
        Texture(std::string file);
        ~Texture();
        bool load();
        GLuint getId();
        void setImageFile(std::string file);
        SDL_Surface* revertPixels(SDL_Surface *sourceImage) const;

    private:
        GLuint m_id;
        std::string m_imageFile;

};

#endif // DEFINE_TEXTURE
