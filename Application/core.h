#ifndef _CORE_H_
#define _CORE_H_

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define PTSIZE 256

struct APP_Ptr {
	SDL_Renderer* renderer;
	SDL_Window* window;
}App;

const char* GlobalFontPath;

TTF_Font* GlobalFont;
#include <memory.h>
#include <stdlib.h>
#include <math.h>
#endif //_CORE_H_
