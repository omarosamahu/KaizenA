#include <Game.h>




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
    
    // playerTex = TextureManager::loadTexture("../assets/img.png",rendrer);
    player = new GameObject("../assets/img.png",rendrer,0,0);
    enemy = new GameObject("../assets/img.png",rendrer,50,50);
}

void Game::update(){
 
    player->Update();
    enemy->Update();   
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
    player->Render();
    enemy->Render();
    SDL_RenderPresent(rendrer);
}
void Game::clean(){
    SDL_Quit();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rendrer);
    std::cout << "Game Cleaned" << std::endl;
}