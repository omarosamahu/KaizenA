#include "Game.h"

Game *mGame = nullptr;
int main(int argc, char const *argv[])
{
    /* code */
    mGame = new Game();

    mGame->init("3amoor Engine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);

    while (mGame->running())
    {
        mGame->render();
        mGame->handleEvent();
        mGame->update();
    }
    mGame->clean();
    return 0;
}
