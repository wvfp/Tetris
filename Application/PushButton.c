#include "PushButton.h"


//在窗口中绘制一个按纽
void drawPushButton(SDL_Renderer* renderer, PushButton* btn){
	if (btn) {
		SDL_Color color = btn->color;
		SDL_Rect rect = btn->rect;
		if (btn->state & PB_STATE_PRESSED || btn->state & PB_STATE_MOUSEONBUTTON) {
			color.r = (Uint8)(color.r * 0.8);
			color.g = (Uint8)(color.g * 0.8);
			color.b = (Uint8)(color.b * 0.8);
			rect.x -= 5;
			rect.y -= 5;
			rect.w += 10;
			rect.h += 10;
		}
		else {
			color = btn->color;
			rect = btn->rect;
		}
		clearWidget(rect, color);

		if (btn->imgTexture != NULL) {
			drawTexture(renderer, btn->imgTexture, rect);
		}
		if (btn->ttfTexture != NULL) {
			drawTexture(renderer, btn->ttfTexture, btn->ttfRect);
		}

		//设置边框颜色
		SDL_Color framColor = color;
		framColor.r = 0xff - framColor.r;
		framColor.g = 0xff - framColor.g;
		framColor.b = 0xff - framColor.b;
		//边框的绘制
		SDL_Rect framRect = rect;
		for (int i = 0; i < 1; i++) {
			SDL_RenderDrawRect(renderer, &framRect);
			framRect.x++;
			framRect.y++;
			framRect.w--;
			framRect.h--;
		}
	}
	return;
}

//按钮的事件处理,按钮状态更改
void PB_EventHandle(SDL_Event* event, PushButton* btn) {
	SDL_Point mousePos = { event->motion.x,event->motion.y };
	if (btn&&btn->state&PB_STATE_ENABLE) {
		switch (event->type) {
		case SDL_MOUSEMOTION:
			if (isPointInRect(mousePos, btn->rect))
				btn->state |= PB_STATE_MOUSEONBUTTON;
			else
				btn->state = PB_STATE_ENABLE;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (isPointInRect(mousePos, btn->rect)) {
				btn->state |= PB_STATE_MOUSEONBUTTON | PB_STATE_PRESSED;
				printf("btn_clicked");
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (isPointInRect(mousePos, btn->rect))
				btn->state |= PB_STATE_MOUSEONBUTTON|PB_STATE_ONRELEASED;
			break;
		default:
			break;
		}
	}
}
