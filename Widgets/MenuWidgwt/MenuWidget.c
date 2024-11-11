#include "MenuWidget.h"

static Uint8 isBtnInit = 0;

static void initBtn() {
	if (!isBtnInit) {
		//给按钮分配内存
		btn_StartGame = (PushButton*)SDL_malloc(sizeof(PushButton));
		btn_Setting = (PushButton*)SDL_malloc(sizeof(PushButton));
		btn_Help = (PushButton*)SDL_malloc(sizeof(PushButton));
		//将按钮的所有位都设置为0
		SDL_memset(btn_StartGame, 0, sizeof(PushButton));
		SDL_memset(btn_Setting, 0, sizeof(PushButton));
		SDL_memset(btn_Help, 0, sizeof(PushButton));
		//初始化按纽StartGame(开始游戏)
		SDL_Rect rect = { WINDOW_WIDTH / 2 - 80,WINDOW_HEIGHT / 2,160,30 };
		btn_StartGame->rect = rect;
		rect.x += 3, rect.y += 3, rect.w -= 6, rect.h -= 6;
		btn_StartGame->ttfRect = rect;
		btn_StartGame->ttfTexture = loadTTFTexture(App.renderer, "StartGame", GlobalFont, SDL_White);
		SDL_Color btn_color = {0x22,0x22,0x22,0xff};
		btn_StartGame->color = btn_color;
		btn_StartGame->state = PB_STATE_ENABLE;
		isBtnInit = 1;
	}
	return;
}

static void freeBtn() {
	if (btn_StartGame) {
		if (btn_StartGame->ttfTexture)
			SDL_DestroyTexture(btn_StartGame->ttfTexture);
		if (btn_StartGame->imgTexture)
			SDL_DestroyTexture(btn_StartGame->imgTexture);
		free(btn_StartGame);
	}
	return;
}

void drawMenuWidget() {
	SDL_Rect rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
	SDL_Color color = {0x30,0x30,0x30,0xff};
	clearWidget(rect, color);
	initBtn();
	drawPushButton(App.renderer,btn_StartGame);
	return;
}

void menuWidgetEventHandle(SDL_Event *event) {
	PB_EventHandle(event, btn_StartGame);
}