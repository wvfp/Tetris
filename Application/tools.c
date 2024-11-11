#include "tools.h"

char isPointInRect(SDL_Point point, SDL_Rect rect) {
	if (point.x > rect.x && point.y > rect.y
		&& point.x < rect.x + rect.w && point.y < rect.y + rect.h) {
		
		return 1;
	}
	else {
		return 0;
	}
}
