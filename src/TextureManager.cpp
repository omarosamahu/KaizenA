#include "TextureManager.h"

SDL_Texture * TextureManager::loadTexture(const char* filename,SDL_Renderer* ren){
    SDL_Surface* tmpSurface = IMG_Load(filename);
    SDL_Texture* mTexture = SDL_CreateTextureFromSurface(ren,tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return mTexture;
}