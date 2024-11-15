#ifndef _CORE_H_
#define _CORE_H_

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define PTSIZE 256

struct APP_Ptr {
	SDL_Renderer* renderer;
	SDL_Window* window;
}App;

const char* GlobalFontPath;

TTF_Font* GlobalFont;

void ((*widgets[5])(void));
void ((*event_handles[5])(SDL_Event*));

unsigned char CURRENT_WIDGET;

#define WIDGET_MENU    0
#define WIDGET_SETTING 1
#define WIDGET_HELP    2
#define WIDGET_GAME    3
#define WIDGET_PAUSE   4
//更改当前Widget
void WidgetChange(unsigned char WIDGET);

#endif //_CORE_H_
