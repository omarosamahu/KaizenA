#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
// Internal
// #include <core.h>
// #include <TextureManager.h>
#include <GameObject.h>

class Game{
public:
    Game();
    ~Game();
    void init(const char* title,int xpos,int ypos,int width,int height,bool flag);
    void clean();
    void handleEvent();
    void update();
    void render();
    inline bool running(){ return isRunning;}
private:
    //SDL_Texture *playerTex;
    //SDL_Rect srcRec,dstrec;
    SDL_Window *window;
    SDL_Renderer *rendrer;
    GameObject* player;
    GameObject* enemy;
    bool isRunning;
    int cnt;
};
#endif