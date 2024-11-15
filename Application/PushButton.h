#ifndef _PUSHBUTTON_H_
#define _PUSHBUTTON_H_

#include "core.h"
#include "draw.h"
#include "tools.h"

//��ť״̬��ö��ֵ
enum PushbuttonState {
	//��ť�Ƿ����
	PB_STATE_ENABLE = 0x01,
	//��ť�Ƿ񱻰�ѹ
	PB_STATE_PRESSED = 0x02,
	//����Ƿ��ڰ�ť��
	PB_STATE_MOUSEONBUTTON = 0x04,
	//��ť�Ƿ��ͷ�
	PB_STATE_ONRELEASED = 0x08
};

struct PushButton;
typedef struct PushButton PushButton;

struct PushButton {
	//��ť��״̬ ö������PushbuttonState PB_STATE_*
	Uint8 state;
	//��ť��λ�úʹ�С
	SDL_Rect rect;
	//���ֵ�λ�úʹ�С
	SDL_Rect ttfRect;
	//��Ŧ����ɫ
	SDL_Color color;
	//ͼƬ
	SDL_Texture* imgTexture;
	//����
	char* text;
	SDL_Texture* ttfTexture;
	//��ť���¼�������
	void (*function)(void*);
	SDL_Event* event;
};

//�ڴ����л���һ����Ŧ
void drawPushButton(SDL_Renderer* renderer, PushButton* btn);
//��ť���¼�����
void PB_EventHandle(SDL_Event* event, PushButton* btn);


#endif // _PUSHBUTTON_H_