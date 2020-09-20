#include <Game.h>

Game *mGame = nullptr;
int main(int argc, char const *argv[])
{
    /* code */
    mGame = new Game();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;

    mGame->init("3amoor Engine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);

    while (mGame->running())
    {
        frameStart = SDL_GetTicks();

        mGame->handleEvent();
        mGame->update();
        mGame->render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    mGame->clean();
    return 0;
}
