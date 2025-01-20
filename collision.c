
#include "cprocessing.h"
#include "collision.h"
#include <stdbool.h>
#include "menu.h"

bool checkCollision(cardObject* card)
{
	if (CP_Input_GetMouseX() >= card->x1 && CP_Input_GetMouseX() <= card->x1 + card->width &&
		CP_Input_GetMouseY() >= card->y1 && CP_Input_GetMouseY() <= card->y1 + card->height)
	{
		drawRect(card, 1);
		return true;
	}
	return false;
} 