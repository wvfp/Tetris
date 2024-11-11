#ifndef _DRAW_H_
#define _DRAW_H_

#include "core.h"

const SDL_Color SDL_White;
const SDL_Color SDL_Black;
const SDL_Color SDL_Red;
const SDL_Color SDL_Greed;
const SDL_Color SDL_Blue;

void clearWindow(void);
void prepareSence(void);
void presentSense(void);
void clearWidget(SDL_Rect,SDL_Color);
void drawTexture(SDL_Renderer*, SDL_Texture*,SDL_Rect);


#endif //_DRAW_H_