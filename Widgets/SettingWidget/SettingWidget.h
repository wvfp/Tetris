#ifndef _SETTINGWIDGET_H_
#define _SETTINGWIDGET_H_

#include "../../Application/core.h"
#include "../../Application/draw.h"
#include "../../Application/PushButton.h"
#include "../../Application/texture.h"

void drawSettingWidget(void);
void settingWidgetEventHandle(SDL_Event*);
void freeSettingWidgetBtn(void);

#endif //_SETTINGWIDGET_H_
