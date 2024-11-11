#include "Application.h"

const char* GlobalFontPath = "../Res/Fonts/game_ttf2.ttf";
//≥ı ºªØ
void APP_Init(char* WidgetName) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG/*|IMG_INIT_JPG|IMG_INIT_WEBP*/);
    TTF_Init();
    App.window = SDL_CreateWindow(WidgetName, 300, 300, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (App.window == NULL) {
        printf("Error: SDL_CreateWindow()\n");
        abort();
    }
    App.renderer= SDL_CreateRenderer(App.window, -1, 0);
    if (App.window == NULL) {
        printf("Error: SDL_CreateRenderer()\n");
        abort();
    }
    SDL_RenderSetLogicalSize(App.renderer, WINDOW_WIDTH, WINDOW_HEIGHT);

    GlobalFont = TTF_OpenFont(GlobalFontPath,PTSIZE);
    printf("TTF:%s\n", SDL_GetError());
    return;
}





