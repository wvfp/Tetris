#ifndef _PUSHBUTTON_H_
#define _PUSHBUTTON_H_

#include "core.h"
#include "draw.h"
#include "tools.h"

//按钮状态的枚举值
enum PushbuttonState {
	//按钮是否可用
	PB_STATE_ENABLE = 0x01,
	//按钮是否被按压
	PB_STATE_PRESSED = 0x02,
	//鼠标是否在按钮上
	PB_STATE_MOUSEONBUTTON = 0x04,
	//按钮是否被释放
	PB_STATE_ONRELEASED = 0x08
};

struct PushButton;
typedef struct PushButton PushButton;

struct PushButton {
	//按钮的状态 枚举类型PushbuttonState PB_STATE_*
	Uint8 state;
	//按钮的位置和大小
	SDL_Rect rect;
	//文字的位置和大小
	SDL_Rect ttfRect;
	//按纽的颜色
	SDL_Color color;
	//图片
	SDL_Texture* imgTexture;
	//文字
	char* text;
	SDL_Texture* ttfTexture;
	//按钮的事件处理函数
	void (*function)(void*);
	SDL_Event* event;
};

//在窗口中绘制一个按纽
void drawPushButton(SDL_Renderer* renderer, PushButton* btn);
//按钮的事件处理
void PB_EventHandle(SDL_Event* event, PushButton* btn);


#endif // _PUSHBUTTON_H_