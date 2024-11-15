// Tetris.cpp: 定义应用程序的入口点。
//
#include "Tetris.h"
#undef main

void initTetris(void);
void freeWidgets(void);
int main(int argc,char*argv[])
{
    SDL_memset(&App, 0, sizeof(App));
    SDL_memset(widgets, 0, sizeof(widgets[0]) * 5);
    SDL_memset(event_handles, 0, sizeof(event_handles[0]) * 5);
    initTetris();
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
            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONUP:
                event_handles[CURRENT_WIDGET](event);
                break;
            default:
                break;
            }
        }
        SDL_Delay(10);
        widgets[CURRENT_WIDGET]();
        presentSense();
    }
    free(event);
    freeWidgets();
    TTF_CloseFont(GlobalFont);
    SDL_Quit();
	return 0;
}

void initTetris(void) {
    //Widgets
    widgets[WIDGET_MENU] = drawMenuWidget;
    widgets[WIDGET_SETTING] = drawSettingWidget;
    widgets[WIDGET_HELP] = drawHelpWidget;
    //event_handles
    event_handles[WIDGET_MENU] = menuWidgetEventHandle;
    event_handles[WIDGET_SETTING] = settingWidgetEventHandle;
    event_handles[WIDGET_HELP] = helpWidgetEventHandle;
   //设置当前活动窗口 
    WidgetChange(WIDGET_MENU);
    return;
}
void freeWidgets(void) {
    freeHelpWidgetBtn();
    freeSettingWidgetBtn();
    freeMenuWidgetBtn();
    #ifdef DEBUG
    printf("Free Widgets\n");
    #endif // DEBUG

}
