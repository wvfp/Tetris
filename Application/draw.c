#include "draw.h"


const SDL_Color SDL_White = {0xff,0xff,0xff,0xff};
const SDL_Color SDL_Black = { 0,0,0,0xff };
const SDL_Color SDL_Red = { 0xff,0,0,0xff };
const SDL_Color SDL_Greed = { 0,0xff,0,0xff };
const SDL_Color SDL_Blue = { 0,0,0xff,0xff };

void clearWindow(void) {
	SDL_Color preColor;
	//获取之前的Renderer的颜色
	SDL_GetRenderDrawColor(App.renderer, &preColor.r, &preColor.g, &preColor.b, &preColor.a);
	//设置Renderer的颜色为白色
	SDL_SetRenderDrawColor(App.renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(App.renderer);
	SDL_SetRenderDrawColor(App.renderer,preColor.a,preColor.g,preColor.b,preColor.a);
	return;
}


void prepareSence(void) {

}
void presentSense(void) {
	SDL_RenderPresent(App.renderer);
}

void clearWidget(SDL_Rect rect,SDL_Color color) {
	SDL_Color preColor;
	//获取之前的Renderer的颜色
	SDL_GetRenderDrawColor(App.renderer, &preColor.r, &preColor.g, &preColor.b, &preColor.a);
	//设置Renderer的颜色为白色
	SDL_SetRenderDrawColor(App.renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(App.renderer,&rect);
	SDL_SetRenderDrawColor(App.renderer, preColor.a, preColor.g, preColor.b, preColor.a);
	return;
}

void drawTexture(SDL_Renderer*renderer, SDL_Texture*texture,SDL_Rect rect) {
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	return;
}
