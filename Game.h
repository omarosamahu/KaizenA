#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

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
    SDL_Window *window;
    SDL_Renderer *rendrer;
    bool isRunning;
    int cnt;
};
#endif