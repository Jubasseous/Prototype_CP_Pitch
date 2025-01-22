
//---------------------------------------------------------
// file:	menu.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:  file for menu gamestate
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//--------------------------------------------------------
#include "cprocessing.h"
#include "menu.h"
#include "drawinglib.h"
#include <stdio.h>
#include "collision.h"
#include <stdlib.h>

#define WINDOW_CENTERW CP_System_GetWindowWidth()/2.f;
#define WINDOW_CENTERH CP_System_GetWindowHeight()/2.f;
#define numOfCards 4

CP_Color background;
CP_Image xCard;
CP_Image oCard;
cardObject* startTrig;
cardObject* start;
cardObject* optionsTrig;
cardObject* options;
//cardObject* creditTrig;
//cardObject* credit;
//cardObject* exitTrig;
//cardObject* exit;
//float posUp[numOfCards];
//const float originalPos[numOfCards]; 
bool inStart;
float posUp;
float originalPos;
float ogHeight;
float cardHeight;
float changeTrig;

float centerW;
float centerH;








// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void menu_init(void)
{
	CP_System_Fullscreen();

	background = CP_Color_Create(100, 10, 200, 180);
	centerW = CP_System_GetWindowWidth() / 2.f;
	centerH = CP_System_GetWindowHeight() / 2.f;


	//CP_Settings_RectMode(CP_POSITION_CENTER); 
	CP_Settings_RectMode(CP_POSITION_CORNER);

	//for flat since their y1 is the same
	originalPos = WINDOW_CENTERH - 200.f;
	posUp = originalPos - 50.f;

	{ //start card
		startTrig = NEWCARDOBJECT;
		if (!startTrig) return;
		startTrig->x1 = 500.f;
		startTrig->y1 = WINDOW_CENTERH - 200.f;
		startTrig->width = 200.f;
		startTrig->height = 300.f;
		startTrig->degrees = 0.f;
		startTrig->cornerRad = 25.f;
		//startTrig->color = CP_Color_Create(0, 150, 100, 255);
		startTrig->color = CP_Color_Create(10, 10, 10, 0);

		start = NEWCARDOBJECT;
		if (!start) return;
		start->x1 = 500.f;
		start->y1 = WINDOW_CENTERH - 200.f;
		start->width = 200.f;
		start->height = 300.f;
		start->degrees = 0.f;
		start->cornerRad = 25.f;
		start->color = CP_Color_Create(0, 0, 100, 255);

		
	}
	
	{ //options
		optionsTrig = NEWCARDOBJECT;
		if (!optionsTrig) return;
		optionsTrig->x1 = 550.f;
		optionsTrig->y1 = WINDOW_CENTERH - 200.f;
		optionsTrig->width = 200.f;
		optionsTrig->height = 300.f;
		optionsTrig->degrees = 20.f;
		optionsTrig->cornerRad = 25.f;
		optionsTrig->color = CP_Color_Create(0, 10, 10, 0);

		options = NEWCARDOBJECT;
		if (!options) return;
		options->x1 = 550.f;
		options->y1 = WINDOW_CENTERH - 200.f;
		options->width = 200.f;
		options->height = 300.f;
		options->degrees = 20.f;
		optionsTrig->cornerRad = 25.f;
		options->color = CP_Color_Create(100, 0, 0, 255);
	}

	{ //for flat face
		ogHeight = 300.f; //original height
		cardHeight = ogHeight + 100.f; //bigger trigger size to account for not touching actual card
		changeTrig = ogHeight - 50.f; //smaller than original to not glitch card
	}
	
	scaleCardStraight(startTrig, start, 2);
	



}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void menu_update(void)
{
	char buffer[100];
	CP_Settings_TextSize(200.f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 250));
	sprintf_s(buffer, sizeof(buffer), "Tic-Dec-Toe");
	CP_Font_DrawText(buffer, centerW, centerH - 400.f);

	// check input, update simulation, render etc.
	CP_Graphics_ClearBackground(background);
	drawRect(startTrig, 1);
	drawRect(start, 1);
	drawRect(optionsTrig, 1);
	drawRect(options, 1);

	popUpFlat(startTrig, start);
	/*if (checkCollision(startTrig))
	{
			//startTrig->color = CP_Color_Create(500, 300, 150, 255);
			startTrig->y1 = posUp;
			startTrig->height = 600.f;

			start->color = CP_Color_Create(100, 0, 0, 250);
			start->y1 = posUp;

			if(checkCollision(start))
			{
				startTrig->height = 500.f;

				if (CP_Input_MouseClicked())
				{
					CP_Graphics_ClearBackground(CP_Color_Create(0, 150, 300, 150));
				}

				inStart = true;
			}


		
			
		
		
	}
	else if (!checkCollision(startTrig) && inStart)
	{
		start->color = CP_Color_Create(0, 0, 100, 150);
		start->y1 = originalPos;
		start->height = 500.f;
	}
	else
	{
		
		//startTrig->color = CP_Color_Create(0, 150, 100, 255);
		startTrig->height = 500.f;
		startTrig->y1 = originalPos;
		
		

		start->color = CP_Color_Create(0, 0, 100, 150);
		start->y1 = originalPos;
		start->height = 500.f;

		inStart = false;
		
	}*/
	


}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void menu_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory

	free(startTrig);
	free(start);
	free(optionsTrig);
	free(options);
}
