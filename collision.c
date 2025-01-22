
#include "cprocessing.h"
#include "collision.h"
#include <stdbool.h>
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int checkCollision(cardObject* card)
{
	if (CP_Input_GetMouseX() >= card->x1 && CP_Input_GetMouseX() <= card->x1 + card->width &&
		CP_Input_GetMouseY() >= card->y1 && CP_Input_GetMouseY() <= card->y1 + card->height)
	{
		return 1;
	}
	return 0;
}

extern float posUp;
extern float originalPos;
extern bool inStart;
extern float ogHeight;
extern float cardHeight;
extern float changeTrig;
extern float centerW;
extern float centerH;



void popUpFlat(cardObject* trig, cardObject* card)
{
	/*float originalPos = orgPos;
	float posUp = originalPos - 100.f;
	bool inStart = 0;*/

	if (checkCollision(trig))
	{
		trig->color = CP_Color_Create(500, 300, 150, 255);
		trig->y1 = posUp;
		trig->height = cardHeight;

		card->color = CP_Color_Create(100, 0, 0, 250);
		card->y1 = posUp;

		if (checkCollision(card))
		{
			trig->height = ogHeight;

			if (CP_Input_MouseClicked())
			{
				CP_Graphics_ClearBackground(CP_Color_Create(0, 150, 300, 150));
			}

			inStart = true;

			char buffer[100];
			CP_Settings_TextSize(100.f);
			CP_Settings_Fill(CP_Color_Create(0,0,0,250));
			sprintf_s(buffer, sizeof(buffer), "Start?");
			CP_Font_DrawText(buffer, centerW + 400.f, centerH - 200.f);
		}

	}
	else if (!checkCollision(trig) && inStart)
	{
		card->color = CP_Color_Create(0, 0, 100, 150);
		card->y1 = originalPos;
		card->height = ogHeight;

		trig->y1 = originalPos;
		trig->height = changeTrig; 
	}
	else
	{

		trig->color = CP_Color_Create(0, 150, 100, 255);
		trig->height = ogHeight;
		trig->y1 = originalPos;

		card->color = CP_Color_Create(0, 0, 100, 150);
		card->y1 = originalPos;
		card->height = ogHeight;

		inStart = false;

	}

}


void popUpDiagonal(cardObject* trig, cardObject* card, int i )
{
	if (checkCollision(trig))
	{
		trig->color = CP_Color_Create(500, 300, 150, 255);
		trig->y1 = posUp;
		trig->height = cardHeight;

		card->color = CP_Color_Create(100, 0, 0, 250);
		card->y1 = posUp;

		if (checkCollision(card))
		{
			trig->height = ogHeight;

			if (CP_Input_MouseClicked())
			{
				CP_Graphics_ClearBackground(CP_Color_Create(0, 150, 300, 150));
			}

			inStart = true;

			char buffer[100];
			CP_Settings_TextSize(100.f);
			CP_Settings_Fill(CP_Color_Create(0, 0, 0, 250));
			sprintf_s(buffer, sizeof(buffer), "Start?");
			CP_Font_DrawText(buffer, centerW + 400.f, centerH - 200.f);
		}

	}
	else if (!checkCollision(trig) && inStart)
	{
		card->color = CP_Color_Create(0, 0, 100, 150);
		card->y1 = originalPos;
		card->height = ogHeight;

		trig->y1 = originalPos;
		trig->height = changeTrig;
	}
	else
	{

		trig->color = CP_Color_Create(0, 150, 100, 255);
		trig->height = ogHeight;
		trig->y1 = originalPos;

		card->color = CP_Color_Create(0, 0, 100, 150);
		card->y1 = originalPos;
		card->height = ogHeight;

		inStart = false;

	}
}
void scaleCardStraight(cardObject* trig, cardObject* card, float scale)
{
	trig->width *= scale;
	trig->height *= scale;

	card->width *= scale;
	card->height *= scale;

	ogHeight *= scale;
	cardHeight *= scale;
	changeTrig *= scale;
}

void scaleCardDiagonal(cardObject* trig, cardObject* card, float scale, int i);

