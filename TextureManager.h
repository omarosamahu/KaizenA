#include "core.h"


class TextureManager{
    public:
        static SDL_Texture* loadTexture(const char* filename,SDL_Renderer * ren);
};