#include "MenuWidget.h"

static PushButton* btn_StartGame;
static PushButton* btn_Setting;
static PushButton* btn_Help;
static Uint8 isBtnInit = 0;
static SDL_Texture* title=NULL;

const SDL_Color Color_Btn = {0xdd,0xdd,0xdd,0xff};

static void initTexture(void) {
	if (title == NULL) {
		title = loadTTFTexture(App.renderer, "Tetris", GlobalFont, Color_Btn);
	}
}

static void btn_Setting_event_handle(void*);
static void btn_Help_event_handle(void*);

static void initBtn(void) {
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
		rect.x += 10, rect.y += -1, rect.w -= 20, rect.h -= 6;
		btn_StartGame->ttfRect = rect;
		btn_StartGame->text = "StartGame";
		btn_StartGame->ttfTexture = loadTTFTexture(App.renderer, btn_StartGame->text, GlobalFont, Color_Btn);
		SDL_Color btn_color = {0x22,0x22,0x22,0xff};
		btn_StartGame->color = btn_color;
		btn_StartGame->state = PB_STATE_ENABLE;
		//初始化按钮btn_Setting
		rect.x -= 10, rect.y +=60-10, rect.w += 20, rect.h += 6;
		btn_Setting->rect = rect;
		rect.x += 10, rect.y +=1, rect.w -= 20, rect.h -= 6;
		btn_Setting->ttfRect = rect;
		btn_Setting->text = "Setting"; 
		btn_Setting->ttfTexture = loadTTFTexture(App.renderer,  btn_Setting->text,GlobalFont,Color_Btn);
		btn_Setting->color = btn_color;
		btn_Setting->function = btn_Setting_event_handle;
		btn_Setting->state = PB_STATE_ENABLE;
		//初始化按钮btn_Help
		rect.x -= 10, rect.y += 60 - 3, rect.w += 20, rect.h += 6;
		btn_Help->rect = rect;
		rect.x += 40, rect.y += 1, rect.w -= 75, rect.h -= 6;
		btn_Help->ttfRect = rect;
		btn_Help->text = "Help";
		btn_Help->ttfTexture = loadTTFTexture(App.renderer, btn_Help->text, GlobalFont, Color_Btn);
		btn_Help->color = btn_color;
		btn_Help->function = btn_Help_event_handle;
		btn_Help->state = PB_STATE_ENABLE;
		isBtnInit = 1;
	}
	return;
}

static void freeBtn(void) {
	if (btn_StartGame) {
		if (btn_StartGame->ttfTexture)
			SDL_DestroyTexture(btn_StartGame->ttfTexture);
		if (btn_StartGame->imgTexture)
			SDL_DestroyTexture(btn_StartGame->imgTexture);
		free(btn_StartGame);
	}
	if (btn_Setting) {
		if (btn_Setting->ttfTexture)
			SDL_DestroyTexture(btn_Setting->ttfTexture);
		if (btn_Setting->imgTexture)
			SDL_DestroyTexture(btn_Setting->imgTexture);
		free(btn_Setting);
	}
	isBtnInit = 0;
	return;
}

void drawMenuWidget(void) {
	SDL_Rect rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
	SDL_Color color = {0x30,0x30,0x30,0xff};
	initTexture();
	clearWidget(rect, color);
	SDL_Rect dstRect = { WINDOW_WIDTH / 2 - 140,WINDOW_HEIGHT / 5,280,60 };
	SDL_RenderCopy(App.renderer, title, NULL,&dstRect);
	initBtn();
	drawPushButton(App.renderer,btn_StartGame);
	drawPushButton(App.renderer,btn_Setting);
	drawPushButton(App.renderer,btn_Help);
	return;
}

void menuWidgetEventHandle(SDL_Event *event) {
	PB_EventHandle(event, btn_StartGame);
	PB_EventHandle(event, btn_Setting);
	PB_EventHandle(event, btn_Help);
}

static void btn_Setting_event_handle(void*message) {
	PushButton* btn = (PushButton*)message;
	WidgetChange(WIDGET_SETTING);
	#ifdef DEBUG
		printf("Widget Change via btn:%s\n", btn ? btn->text : "btn");
	#endif // DEBUG

}
static void btn_Help_event_handle(void*message) {
	PushButton* btn = (PushButton*)message;
	WidgetChange(WIDGET_HELP);
	#ifdef DEBUG
	printf("Widget Change via btn:%s\n", btn ? btn->text : "btn");
	#endif // DEBUG
}
void freeMenuWidgetBtn(void) {
	freeBtn();
	if (title) {
		SDL_DestroyTexture(title);
		title = NULL;
	}
}
