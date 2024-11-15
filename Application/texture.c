#include "texture.h"
//根据路径加载图片，返回一个图片表面
SDL_Surface* loadImgSurface(SDL_Renderer*renderer, const char*path) {
	SDL_Surface* surface = NULL;
	surface = IMG_Load(path);
	if (!surface) {
		printf("Warning Image(:%s) Surface can not be load.\n%s", path,SDL_GetError());
	}
	return surface;
}
//根据文本和字体与颜色创建一个表面
SDL_Surface* loadTTFSurface(SDL_Renderer*renderer,const  char*text, TTF_Font*font, SDL_Color color) {
	SDL_Surface* surface = NULL;
	surface = TTF_RenderUTF8_Blended_Wrapped(font, text, color,0);
	if (!surface) {
		printf("Warring:Text(:%s) Surface can not be load.\n%s",text,SDL_GetError());
	}
	return surface;
}
//根据路径加载图片，返回一个图片纹理
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
//根据文本和字体与颜色创建一个纹理
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