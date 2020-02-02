#include "utils.h"

int main(int argc, char *args[])
{
    bool quit = false;
    if (init() == false || load_files() == false)
    {
        return 1;
    }
    next_time = SDL_GetTicks() + TICK_INTERVAL;

    //Apply the background to the screen
    initBg(screen, background);
    color.b = 155;

    while (quit == false)
    {

        initBg(screen, background);
        SDL_Delay(33);

        if (running == true)
        {
            char time[50];
            sprintf(time, "%d", SDL_GetTicks());
            SDL_Surface *seconds = generateFontSurface("", 50, time, color);
            apply_surface((SCREEN_WIDTH - seconds->w) / 2, 100, seconds, screen, NULL);
        }

        char menuselectchar[10];
        sprintf(menuselectchar, "%d", menuSelect);
        SDL_Surface *menuSelection = generateFontSurface("", 40, menuselectchar, color);
        apply_surface((SCREEN_WIDTH - menuSelection->w) / 2, 50, menuSelection, screen, NULL);

        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                //if (menuSelect != 0)
                {
                    menuSelect--;
                }
                break;
            case SDLK_DOWN:
                //if (menuSelect != 3)
                {
                    menuSelect++;
                }
                break;
            case (SDLK_s):
                running == !running;
            }
            break;
        default:
            break;
        }
        SDL_Flip(screen);
    }
    clean_up();
    return 0;
}