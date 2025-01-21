
#include "cprocessing.h"
#include "collision.h"
#include <stdbool.h>
#include "menu.h"

int checkCollision(cardObject* card)
{
	if (CP_Input_GetMouseX() >= card->x1 && CP_Input_GetMouseX() <= card->x1 + card->width &&
		CP_Input_GetMouseY() >= card->y1 && CP_Input_GetMouseY() <= card->y1 + card->height)
	{
		return 1;
	}
	return 0;
}


void popUpFlat(cardObject* trig, cardObject* card);

	/*float originalPos = trig->y1;
	float posUp = originalPos - 100.f;
	if (checkCollision(trig))
	{
		trig->color = CP_Color_Create(500, 300, 150, 255);
		trig->y1 = posUp;
		trig->height = 600.f;

		card->color = CP_Color_Create(100, 0, 0, 0);
		card->y1 = posUp;

		if (checkCollision(card))
		{
			trig->height = 500.f;

			if (CP_Input_MouseClicked())
			{
				CP_Graphics_ClearBackground(CP_Color_Create(0, 150, 300, 150));
			}
		}






	}
	else
	{

		trig->color = CP_Color_Create(0, 150, 100, 255);
		trig->height = 500.f;
		trig->y1 = originalPos;

		start->color = CP_Color_Create(0, 0, 100, 150);
		start->y1 = originalPos;
		startTrig->height = 500.f;

	}
}*/