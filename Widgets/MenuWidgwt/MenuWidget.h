#ifndef _MENUWIDGET_H_
#define _MENUWIDGET_H_


#include "../../Application/core.h"
#include "../../Application/draw.h"
#include "../../Application/PushButton.h"
#include "../../Application/texture.h"
PushButton* btn_StartGame;
PushButton* btn_Setting;
PushButton* btn_Help;
static Uint8 isBtnInit;

void drawMenuWidget();
void menuWidgetEventHandle(SDL_Event*);

#endif // _MENUWIDGET_H_
