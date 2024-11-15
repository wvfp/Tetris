#include "texture.h"
//����·������ͼƬ������һ��ͼƬ����
SDL_Surface* loadImgSurface(SDL_Renderer*renderer, const char*path) {
	SDL_Surface* surface = NULL;
	surface = IMG_Load(path);
	if (!surface) {
		printf("Warning Image(:%s) Surface can not be load.\n%s", path,SDL_GetError());
	}
	return surface;
}
//�����ı�����������ɫ����һ������
SDL_Surface* loadTTFSurface(SDL_Renderer*renderer,const  char*text, TTF_Font*font, SDL_Color color) {
	SDL_Surface* surface = NULL;
	surface = TTF_RenderUTF8_Blended_Wrapped(font, text, color,0);
	if (!surface) {
		printf("Warring:Text(:%s) Surface can not be load.\n%s",text,SDL_GetError());
	}
	return surface;
}
//����·������ͼƬ������һ��ͼƬ����
SDL_Texture* loadImgTexture(SDL_Renderer*renderer,const char*path) {
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = loadImgSurface(renderer, path);
	if (surface) {
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		if(!texture)
			printf("Can not load image txetue(path:%s)\n%s", path, SDL_GetError());
		SDL_FreeSurface(surface);
	}
	return texture;
}
//�����ı�����������ɫ����һ������
SDL_Texture* loadTTFTexture(SDL_Renderer*renderer, const char*text, TTF_Font*font, SDL_Color color) {
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = loadTTFSurface(renderer,text,font,color);
	if (surface) {
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (!texture)
			printf("Can not load text texture(:%s).\n%s", text, SDL_GetError());
		SDL_FreeSurface(surface);
	}
	return texture;
}