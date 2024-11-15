#ifndef _HELPWIDGET_H_
#define _HELPWIDGET_H_
#include "../../Application/core.h"
#include "../../Application/draw.h"
#include "../../Application/PushButton.h"
#include "../../Application/texture.h"
//#include <mxml.h>



void drawHelpWidget(void);
void helpWidgetEventHandle(SDL_Event*);
void freeHelpWidgetBtn(void);

#endif // _HELPWIDGET_H_
