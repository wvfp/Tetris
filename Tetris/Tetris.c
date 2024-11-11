// Tetris.cpp: 定义应用程序的入口点。
//
#include "Tetris.h"
#undef main

int main(int argc,char*argv[])
{
    memset(&App, 0, sizeof(App));
	APP_Init("Tetris");
	SDL_Event* event=(SDL_Event*)malloc(sizeof(SDL_Event));
    if (event == NULL) {
        exit(-1);
    }
    SDL_Rect rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
    SDL_Color color = {0,0xff,0xff,0xff};
	clearWindow();
    presentSense();
    drawMenuWidget();
    //游戏循环
	while (1){
        while (SDL_PollEvent(event))
        {
            switch (event->type)
            {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                menuWidgetEventHandle(event);
                break;
            case SDL_MOUSEMOTION:
                menuWidgetEventHandle(event);
                break;
            case SDL_MOUSEBUTTONUP:
                menuWidgetEventHandle(event);
                break;
            default:
                break;
            }
        }
        SDL_Delay(10);
        drawMenuWidget();
        presentSense();
    }
    free(event);
    TTF_CloseFont(GlobalFont);
    SDL_Quit();
	return 0;
}
