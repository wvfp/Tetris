#ifndef _GAMEWIDGET_H_
#define _GAMEWIDGET_H_
#include "../../Application/core.h"
#include "../../Application/draw.h"
#include "../../Application/PushButton.h"
#include "../../Application/texture.h"

void drawGameWidget(void);
void gameWidgetEventHandle(SDL_Event*);
void freeGameWidgetBtn(void);
#endif // _GAMEWIDGET_H_
