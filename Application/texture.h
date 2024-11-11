#include "core.h"

SDL_Surface* loadImgSurface(SDL_Renderer*, char*);

SDL_Surface* loadTTFSurface(SDL_Renderer*, char*,TTF_Font*,SDL_Color);

SDL_Texture* loadImgTexture(SDL_Renderer*, char*);

SDL_Texture* loadTTFTexture(SDL_Renderer*, char*,TTF_Font*,SDL_Color);
