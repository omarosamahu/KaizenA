#include "Game.h"

SDL_Texture *playerTex;
SDL_Rect srcRec,dstrec;

Game::Game(){}

Game::~Game(){}

void Game::init(const char* title,int xpos,int ypos,int width,int height,bool flag){
    auto mFlag = SDL_WINDOW_SHOWN;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
     if(flag){
        mFlag = SDL_WINDOW_FULLSCREEN;
    }    
    window = SDL_CreateWindow(title,xpos,ypos,width,height,mFlag);
    
    if(window){
        std::cout << "Window Initilized" << std::endl;
    }

    rendrer = SDL_CreateRenderer(window,-1,0);

    if(rendrer){
        SDL_SetRenderDrawColor(rendrer,255,255,255,255);
        std::cout << "Renderer Initilized" << std::endl;
    }
   
    
    isRunning = true;
    }
    else{
        isRunning = false;
    }
    SDL_Surface *tmpSurface = IMG_Load("assets/img.png");
    playerTex = SDL_CreateTextureFromSurface(rendrer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::update(){
    cnt += 1;

    dstrec.h = 64;
    dstrec.w = 64;
    dstrec.x = cnt;
    
}

void Game::handleEvent(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}
void Game::render(){
    SDL_RenderClear(rendrer);
    SDL_RenderCopy(rendrer,playerTex,NULL,&dstrec); 
    SDL_RenderPresent(rendrer);
}
void Game::clean(){
    SDL_Quit();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rendrer);
    std::cout << "Game Cleaned" << std::endl;
}