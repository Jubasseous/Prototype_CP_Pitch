
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

#define numOfCards 4

extern float posUp[numOfCards];
extern float posUpX[numOfCards];
extern float originalPos[numOfCards];
extern bool in;
extern float ogHeight[numOfCards];
extern float cardHeight[numOfCards];
extern float changeTrig[numOfCards];
extern float ogWidth[numOfCards];
extern float cardWidth[numOfCards];
extern float changeTrigX[numOfCards];
extern float centerW;
extern float centerH;



void resetCard(cardObject* card, cardObject* trig, cardObject* OG, int i)
{
	card->y1 = originalPos[i];
	trig->y1 = originalPos[i];
	OG->y1 = originalPos[i];
	OG->height = 270.f * 2;
	trig->height = 270.f * 2;
}
//void popUpFlat(cardObject* trig, cardObject* card)
//{
//	/*float originalPos = orgPos;
//	float posUp = originalPos - 100.f;
//	bool inStart = 0;*/
//
//	if (checkCollision(trig))
//	{
//		trig->color = CP_Color_Create(500, 300, 150, 255);
//		trig->y1 = posUp;
//		trig->height = cardHeight;
//
//		card->color = CP_Color_Create(100, 0, 0, 250);
//		card->y1 = posUp;
//
//		if (checkCollision(card))
//		{
//			trig->height = ogHeight;
//
//			if (CP_Input_MouseClicked())
//			{
//				CP_Graphics_ClearBackground(CP_Color_Create(0, 150, 300, 150));
//			}
//
//			in = true;
//
//			char buffer[100];
//			CP_Settings_TextSize(100.f);
//			CP_Settings_Fill(CP_Color_Create(0,0,0,250));
//
//			switch (i)
//			{
//				case 0:
//					sprintf_s(buffer, sizeof(buffer), "Start");
//					break;
//				case 1:
//					sprintf_s(buffer, sizeof(buffer), "Options");
//					break;
//				case 2:
//					sprintf_s(buffer, sizeof(buffer), "Credits");
//					break;
//				case 3:
//					sprintf_s(buffer, sizeof(buffer), "Exit");
//					break;
//			}
//
//			CP_Font_DrawText(buffer, centerW + 400.f, centerH - 200.f);
//		}
//
//	}
//	else if (!checkCollision(trig) && in)
//	{
//		card->color = CP_Color_Create(0, 0, 100, 150);
//		card->y1 = originalPos;
//		card->height = ogHeight;
//
//		trig->y1 = originalPos;
//		trig->height = changeTrig; 
//	}
//	else
//	{
//
//		trig->color = CP_Color_Create(0, 150, 100, 255);
//		trig->height = ogHeight;
//		trig->y1 = originalPos;
//
//		card->color = CP_Color_Create(0, 0, 100, 150);
//		card->y1 = originalPos;
//		card->height = ogHeight;
//
//		in= false;
//
//	}
//
//}


void popUp(cardObject* trig, cardObject* card, cardObject* ogTrig, int i, bool hovering )
{
	if (hovering)
	{
		if (checkCollision(trig))
		{
			//trig->color = CP_Color_Create(500, 300, 150, 255);
			trig->y1 = posUp[i];
			trig->height = cardHeight[i];

			


			//card->color = CP_Color_Create(100, 0, 0, 250);
			card->y1 = posUp[i];

			ogTrig->y1 = card->y1;

			if (checkCollision(card))
			{
				trig->height = ogHeight[i];
				ogTrig->height = trig->height;

				if (CP_Input_MouseClicked())
				{
					CP_Graphics_ClearBackground(CP_Color_Create(0, 150, 300, 150));
				}

				in = true;

				char buffer[100];
				CP_Settings_TextSize(100.f);
				CP_Settings_Fill(CP_Color_Create(0, 0, 0, 250));

				switch (i)
				{
				case 0:
					sprintf_s(buffer, sizeof(buffer), "Start");
					break;
				case 1:
					sprintf_s(buffer, sizeof(buffer), "Options");
					break;
				case 2:
					sprintf_s(buffer, sizeof(buffer), "Credits");
					break;
				case 3:
					sprintf_s(buffer, sizeof(buffer), "Exit");
					break;
				}

				CP_Font_DrawText(buffer, centerW + 400.f, centerH - 200.f);
			}

		}
		//else if (!checkCollision(trig) && in)
		//{
		//	//card->color = CP_Color_Create(0, 0, 100, 150);
		//	card->y1 = originalPos[i];
		//	card->height = ogHeight[i];

		//	trig->y1 = originalPos[i];
		//	trig->height = changeTrig[i];

		//	ogTrig->y1 = card->y1;
		//	ogTrig->height = card->height - 10.f;
		//}
		//else
		//{

		//	//trig->color = CP_Color_Create(0, 150, 100, 255);
		//	trig->height = ogHeight[i];
		//	trig->y1 = originalPos[i];

		//	

		//	//card->color = CP_Color_Create(0, 0, 100, 150);
		//	card->y1 = originalPos[i];
		//	card->height = ogHeight[i];
		//	ogTrig->y1 = card->y1;
		//	ogTrig->height = card->height - 10.f;

		//	in = false;

		//}
	}
	
}
void scaleCardStraight(cardObject* trig, cardObject* card, float scale, int i)
{
	trig->width *= scale;
	trig->height *= scale;

	card->width *= scale;
	card->height *= scale;

	ogHeight[i] *= scale;
	cardHeight[i] *= scale;
	changeTrig[i] *= scale;
}
void scaleCard(cardObject* trig, float scale)
{
	trig->width *= scale;
	trig->height *= scale;

}

//void scaleCardDiagonal(cardObject* trig, cardObject* card, float scale, int i)
//{
//	trig->width *= scale;
//	trig->height *= scale;
//
//	card->width *= scale;
//	card->height *= scale;
//
//	ogHeight[i] *= scale;
//	cardHeight[i] *= scale;
//	changeTrig[i] *= scale;
//
//	if (i != 0) //if it's diagonal since the only card straight is start
//	{
//		ogWidth[i] *= scale;
//		cardWidth[i] *= scale;
//		changeTrigX[i] *= scale;
//
//	}
//	
//
//}


