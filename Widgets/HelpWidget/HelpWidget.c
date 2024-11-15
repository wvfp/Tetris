#include "HelpWidget.h"

static PushButton* btn_Back=NULL;
static PushButton* btn_Next=NULL;
static Uint8 isBtnInit = 0;
static SDL_Texture* title = NULL;
const char* pageOne = " Tetris control by keyborad :\n"
"\tW / UpArrow : Clockwise Rotation.\n"
"S / DownArrow : Hard Drop\n"
"A / LeftArrow : Move Left\n"
"D / RightArrow : Move Right\n"
"Space : Soft Drop\n";
const char* pageTwo = "	Others control by keyborad:\n"
"P / Esc   : Pause Game\n"
"R / Enter : Restart Game\n";

static Uint8 pageIndex=1;
static SDL_Texture* pageOneTexture;
static SDL_Texture* pageTwoTexture;

//static const SDL_Color Color_Btn = { 0xdd,0xdd,0xdd,0xff };
static void btn_back_event_handle(void*);
static void btn_next_event_handle(void*);
static char* loadTextFromXML(int);
static void initTexture(void) {
	if (title == NULL) 
		title = loadTTFTexture(App.renderer, "Help", GlobalFont, Color_Btn);
	if(pageOneTexture==NULL)
		pageOneTexture = loadTTFTexture(App.renderer, pageOne, GlobalFont, Color_Btn);
	if(pageTwoTexture==NULL)
		pageTwoTexture = loadTTFTexture(App.renderer, pageTwo, GlobalFont, Color_Btn);
}

static void initBtn(void) {
	if (!isBtnInit) {
		if(btn_Back==NULL)
			btn_Back = (PushButton*)SDL_malloc(sizeof(PushButton));
		if(btn_Next==NULL)
			btn_Next = (PushButton*)SDL_malloc(sizeof(PushButton));
		//将位初始化为0
		SDL_memset(btn_Back, 0, sizeof(PushButton));
		SDL_memset(btn_Next, 0, sizeof(PushButton));

		//初始化按纽Back(返回)
		SDL_Rect rect = { WINDOW_WIDTH / 2 - 80,WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 3 - 35,70,25 };
		btn_Back->rect = rect;
		rect.x += 10, rect.y += -1, rect.w -= 20, rect.h -= 6;
		btn_Back->ttfRect = rect;
		btn_Back->text = "Back";
		btn_Back->ttfTexture = loadTTFTexture(App.renderer, btn_Back->text, GlobalFont, Color_Btn);
		SDL_Color btn_color = { 0x22,0x22,0x22,0xff };
		btn_Back->color = btn_color;
		btn_Back->function = btn_back_event_handle;
		btn_Back->state = PB_STATE_ENABLE;

		//初始化按纽Next(音乐)
		SDL_Rect next_Rect = { WINDOW_WIDTH / 2 + WINDOW_WIDTH / 5 - 80,WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 3 - 35,70,25 };
		btn_Next->rect = next_Rect;
		next_Rect.x += 10, next_Rect.y += -1, next_Rect.w -= 20, next_Rect.h -= 6;
		btn_Next->ttfRect = next_Rect;
		btn_Next->text = "Next";
		btn_Next->ttfTexture = loadTTFTexture(App.renderer, btn_Next->text, GlobalFont, Color_Btn);
		btn_Next->color = btn_color;
		btn_Next->function = btn_next_event_handle;
		btn_Next->state = PB_STATE_ENABLE;
		isBtnInit = 1;
	}
}

static void freeTexture(void) {
	if (title) {
		SDL_DestroyTexture(title);
		title = NULL;
	}
	if (pageOneTexture) {
		SDL_DestroyTexture(pageOneTexture);
		pageOneTexture = NULL;
	}
	if (pageOneTexture) {
		SDL_DestroyTexture(pageTwoTexture);
		pageTwoTexture = NULL;
	}
	pageIndex = 1;
}

static void freeBtn(void) {
	if (btn_Back) {
		if (btn_Back->ttfTexture)
			SDL_DestroyTexture(btn_Back->ttfTexture);
		if (btn_Back->imgTexture)
			SDL_DestroyTexture(btn_Back->imgTexture);
		//free(btn_Back);
	}
	if (btn_Next) {
		if (btn_Next->ttfTexture)
			SDL_DestroyTexture(btn_Next->ttfTexture);
		if (btn_Next->imgTexture)
			SDL_DestroyTexture(btn_Next->imgTexture);
		//free(btn_Next);
	}
	isBtnInit = 0;
	return;

}

void drawHelpWidget(void) {
	SDL_Rect rect = { WINDOW_WIDTH / 4+10,WINDOW_HEIGHT / 3+10,WINDOW_WIDTH / 2,WINDOW_HEIGHT /2 };
	SDL_Color color = { 0x20,0x20,0x20,0xff };
	initTexture();
	clearWidget(rect, color);
	SDL_Rect dstRect = { WINDOW_WIDTH / 4+120,WINDOW_HEIGHT /3+15,100,30 };
	SDL_RenderCopy(App.renderer, title, NULL, &dstRect);
	initBtn();
	drawPushButton(App.renderer, btn_Back);
	drawPushButton(App.renderer, btn_Next);
	SDL_Rect T_rect; 
	SDL_Texture* currentTexture;
	if (pageIndex == 1) {
		currentTexture = pageOneTexture;
		T_rect.x= WINDOW_WIDTH / 4 + 20;
		T_rect.y= WINDOW_HEIGHT / 3 + 50;
		T_rect.w=  WINDOW_WIDTH / 2 - 10;
		T_rect.h= WINDOW_HEIGHT / 2 - 100;
	}
	else {
		currentTexture = pageTwoTexture;
		T_rect.x= WINDOW_WIDTH / 4 + 20;
		T_rect.y= WINDOW_HEIGHT / 3 +50;
		T_rect.w=  WINDOW_WIDTH / 2 - 100;
		T_rect.h= WINDOW_HEIGHT / 2 - 150;
	}
	SDL_RenderCopy(App.renderer, currentTexture, NULL,&T_rect);
}

void helpWidgetEventHandle(SDL_Event*event) {
	PB_EventHandle(event, btn_Back);
	PB_EventHandle(event, btn_Next);
}

static void btn_back_event_handle(void* message) {
	WidgetChange(WIDGET_MENU);
	freeTexture();
	freeBtn();
}
static void btn_next_event_handle(void*message) {
	if (pageIndex == 1)
		pageIndex = 2;
	else
		pageIndex = 1;
}

void freeHelpWidgetBtn(void) {
	if (btn_Back)
		free(btn_Back);
	if (btn_Next)
		free(btn_Next);
}

/*
static char* loadTextFromXML(int i) {
	//打开文件，获取文件流
	FILE* fp = fopen("../Res/Xmls/Help/text.xml", "r");
	mxml_node_t* root = mxmlLoadFile(NULL, NULL,fp);
	char* index = (char*)SDL_malloc(sizeof(char) * 2);
	index[1] = '\0';
	index[0] = '0' + i;
	mxml_node_t* node = mxmlFindElement(root, root, "Part","index", index, MXML_DESCEND_ALL);
	mxml_node_t* text;
	char* str;
	if (node != NULL) {
		text = mxmlFindElement(node, root, "text", NULL, NULL, MXML_DESCEND_ALL);
		if (text) {
			str = mxmlGetText(text,NULL);
		}
	}
	//关闭文件流
	//fclose(fp);
}
*/