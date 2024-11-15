#ifndef _MENUWIDGET_H_
#define _MENUWIDGET_H_


#include "../../Application/core.h"
#include "../../Application/draw.h"
#include "../../Application/PushButton.h"
#include "../../Application/texture.h"

void drawMenuWidget(void);
void menuWidgetEventHandle(SDL_Event*);
void freeMenuWidgetBtn(void);
#endif // _MENUWIDGET_H_
