#include "SettingWidget.h"


static PushButton* btn_Music;
static PushButton* btn_Back;
static SDL_Texture* title;
static Uint8 isBtnInit = 0;

static void initTexture(void) {
	if (title == NULL) {
		title = loadTTFTexture(App.renderer,"Setting",GlobalFont,Color_Btn);
	}
}


static void btn_music_event_handle(void*);
static void btn_back_event_handle(void*);

static void initBtn(void) {
	if (!isBtnInit) {
		//分配内存
		btn_Back= (PushButton*)SDL_malloc(sizeof(PushButton));
		btn_Music= (PushButton*)SDL_malloc(sizeof(PushButton));
		//将位初始化为0
		SDL_memset(btn_Back, 0, sizeof(PushButton));
		SDL_memset(btn_Music, 0, sizeof(PushButton));

		//初始化按纽Back(返回)
		SDL_Rect rect = { WINDOW_WIDTH / 2 + WINDOW_WIDTH/4-80,WINDOW_HEIGHT / 2+WINDOW_HEIGHT/3-35,70,25 };
		btn_Back->rect = rect;
		rect.x += 10, rect.y += -1, rect.w -= 20, rect.h -= 6;
		btn_Back->ttfRect = rect;
		btn_Back->text = "Back";
		btn_Back->ttfTexture = loadTTFTexture(App.renderer, btn_Back->text, GlobalFont, Color_Btn);
		SDL_Color btn_color = { 0x22,0x22,0x22,0xff };
		btn_Back->color = btn_color;
		btn_Back->function = btn_back_event_handle;
		btn_Back->state = PB_STATE_ENABLE;
		
		//初始化按纽Music(音乐)
		SDL_Rect music_Rect = { WINDOW_WIDTH / 2 - 120,WINDOW_HEIGHT / 2 + 70,100,30 };
		btn_Music->rect = music_Rect;
		music_Rect.x += 10, music_Rect.y += -1, music_Rect.w -= 20, music_Rect.h -= 6;
		btn_Music->ttfRect = music_Rect;
		btn_Music->text = "Music:ON";
		btn_Music->ttfTexture = loadTTFTexture(App.renderer, btn_Music->text, GlobalFont, Color_Btn);
		btn_Music->color = btn_color;
		btn_Music->function=btn_music_event_handle;
		btn_Music->state = PB_STATE_ENABLE;
		isBtnInit = 1;
	}
}
void static freeBtn() {
	if (btn_Back) {
		if (btn_Back->ttfTexture)
			SDL_DestroyTexture(btn_Back->ttfTexture);
		if (btn_Back->imgTexture)
			SDL_DestroyTexture(btn_Back->imgTexture);
		free(btn_Back);
	}
	if (btn_Music) {
		if (btn_Music->ttfTexture)
			SDL_DestroyTexture(btn_Music->ttfTexture);
		if (btn_Music->imgTexture)
			SDL_DestroyTexture(btn_Music->imgTexture);
		free(btn_Music);
	}
	isBtnInit = 0;
	return;
}

void drawSettingWidget(void) {
	SDL_Color color = { 0x20,0x20,0x20,0xff };
	SDL_Rect rect = { WINDOW_WIDTH / 4+10,WINDOW_HEIGHT / 2,WINDOW_WIDTH / 2,WINDOW_HEIGHT /3 };
	initTexture();
	clearWidget(rect, color);
	SDL_Rect dstRect = { WINDOW_WIDTH / 4+100,WINDOW_HEIGHT /2+10,100,30 };
	SDL_RenderCopy(App.renderer, title, NULL, &dstRect);
	initBtn();
	drawPushButton(App.renderer, btn_Back);
	drawPushButton(App.renderer, btn_Music);
}
void settingWidgetEventHandle(SDL_Event*event) {
	PB_EventHandle(event, btn_Back);
	PB_EventHandle(event, btn_Music);
}

static void btn_music_event_handle(void*message) {
	PushButton* btn = (PushButton*)message;
	if (btn != NULL) {
		if (SDL_strcmp(btn->text, "Music:ON")==0) {
			if (btn->ttfTexture) {
				SDL_DestroyTexture(btn->ttfTexture);
				btn->text = "Music:OFF";
				btn->ttfTexture = loadTTFTexture(App.renderer, btn->text,
					GlobalFont, Color_Btn);
				btn->ttfRect.w += btn->ttfRect.w / 8;
			}
		}
		else {
			if (btn->ttfTexture) {
				SDL_DestroyTexture(btn->ttfTexture);
				btn->text = "Music:ON";
				btn->ttfTexture = loadTTFTexture(App.renderer, btn->text,
					GlobalFont, Color_Btn);
				btn->ttfRect.w -= btn->ttfRect.w / 9;
			}
		}
	}
}

static void btn_back_event_handle(void*message) {
	WidgetChange(WIDGET_MENU);
}
void freeSettingWidgetBtn(void) {
	freeBtn();
	if (title) {
		SDL_DestroyTexture(title);
		title = NULL;
	}
}