#include "core.h"

SDL_Surface* loadImgSurface(SDL_Renderer*, const char*);

SDL_Surface* loadTTFSurface(SDL_Renderer*, const char*,TTF_Font*,SDL_Color);

SDL_Texture* loadImgTexture(SDL_Renderer*, const char*);

SDL_Texture* loadTTFTexture(SDL_Renderer*, const char*,TTF_Font*,SDL_Color);
