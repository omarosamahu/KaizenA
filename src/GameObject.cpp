#include <GameObject.h>
#include <TextureManager.h> 


GameObject::GameObject(const char* textureSheet,SDL_Renderer* ren,int x,int y){
    mRenderer = ren;
    mTexture = TextureManager::loadTexture(textureSheet,ren);

    xpos = x;
    ypos = y;
}

GameObject::~GameObject(){

}

void GameObject::Update(){
    xpos++;
    ypos++;

    srcRec.x = 0;
    srcRec.y = 0;
    srcRec.w = 64;
    srcRec.h = 64;

    

    dstRec.x = xpos;
    dstRec.y = ypos;
    dstRec.w = srcRec.w * 2;
    dstRec.h = srcRec.h * 2;

    
}

void GameObject::Render(){
    
    SDL_RenderCopy(mRenderer,mTexture,&srcRec,&dstRec); 
}
