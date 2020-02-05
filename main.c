#include "utils.h"

int main(int argc, char *args[])
{
    bool quit = false;
    if (init() == false || load_files() == false || loadMusic() == false)
    {
        printf("Initialization Failed \n");
        return -1;
    }
    int menuSelect = 0;
    while (quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            initBg(screen, background);
            SDL_Delay(33);

            loadMenuFiles();
            initMenu(menuSelect);
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                Mix_PlayChannel(-1, low, 0);
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RETURN:
                    if (menuSelect == 2)
                        quit = true;
                    break;
                case SDLK_BACKSPACE:
                    Mix_PlayChannel(-1, med, 0);
                    break;
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                case SDLK_UP:
                    Mix_PlayChannel(-1, low, 0);
                    if (menuSelect != 0)
                        menuSelect--;
                    break;
                case SDLK_DOWN:
                    Mix_PlayChannel(-1, low, 0);
                    if (menuSelect != 2)
                        menuSelect++;
                    break;
                case (SDLK_s):
                    running = !running;
                }
                break;
            default:
                break;
            }
            SDL_Flip(screen);
        }
    }
    clean_up();
    return 0;
}
