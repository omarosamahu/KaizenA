#include <core.h>

class GameObject{
public:
    GameObject(const char* textureSheet,SDL_Renderer* ren,int x,int y);
    ~GameObject();

    void Update();
    void Render();
private:
    SDL_Texture* mTexture;
    SDL_Renderer* mRenderer;
    SDL_Rect srcRec,dstRec;
    int xpos;
    int ypos;
};