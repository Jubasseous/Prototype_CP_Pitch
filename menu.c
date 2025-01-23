
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
cardObject* startOGTrig;
cardObject* optionsTrig;
cardObject* options;
cardObject* optionsOGTrig;
cardObject* creditsTrig;
cardObject* credits;
cardObject* creditsOGTrig;
cardObject* leaveTrig;
cardObject* leave;
cardObject* leaveOGTrig;
//float posUp[numOfCards];
//const float originalPos[numOfCards]; 
bool in;
float posUp[numOfCards];
//float posUpX[numOfCards];
float originalPos[numOfCards];
float ogHeight[numOfCards];
float cardHeight[numOfCards];
float changeTrig[numOfCards];
float ogWidth[numOfCards];
float cardWidth[numOfCards];
float changeTrigX[numOfCards];

float centerW;
float centerH;


bool checkCard[numOfCards];








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
	/*originalPos = WINDOW_CENTERH - 200.f;
	posUp = originalPos - 50.f;*/

	//start card
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

		startOGTrig = NEWCARDOBJECT;
		if (!startOGTrig) return;
		startOGTrig->x1 = 500.f;
		startOGTrig->y1 = WINDOW_CENTERH - 200.f;
		startOGTrig->width = 200.f;
		startOGTrig->height = 300.f;
		startOGTrig->degrees = 0.f;
		startOGTrig->cornerRad = 25.f;
		//startTrig->color = CP_Color_Create(0, 150, 100, 255);
		startOGTrig->color = CP_Color_Create(10, 10, 10, 0);


	
	 //options
		optionsTrig = NEWCARDOBJECT;
		if (!optionsTrig) return;
		optionsTrig->x1 = 600.f;
		optionsTrig->y1 = WINDOW_CENTERH - 200.f;
		optionsTrig->width = 200.f;
		optionsTrig->height = 300.f;
		optionsTrig->degrees = 0.f;
		optionsTrig->cornerRad = 25.f;
		optionsTrig->color = CP_Color_Create(10, 0, 10, 0);

		options = NEWCARDOBJECT;
		if (!options) return;
		options->x1 = 600.f;
		options->y1 = WINDOW_CENTERH - 200.f;
		options->width = 200.f;
		options->height = 300.f;
		options->degrees = 0.f;
		options->cornerRad = 25.f;
		options->color = CP_Color_Create(100, 0, 0, 255);

		optionsOGTrig = NEWCARDOBJECT;
		if (!optionsOGTrig) return;
		optionsOGTrig->x1 = 898.f;
		optionsOGTrig->y1 = WINDOW_CENTERH - 200.f;
		optionsOGTrig->width = 50.f;
		optionsOGTrig->height = 290.f;
		optionsOGTrig->degrees = 0.f;
		optionsOGTrig->cornerRad = 25.f;
		optionsOGTrig->color = CP_Color_Create(0, 0, 0, 0);

	//credits
		creditsTrig = NEWCARDOBJECT;
		if (!creditsTrig) return;
		creditsTrig->x1 = 700.f;
		creditsTrig->y1 = WINDOW_CENTERH - 200.f;
		creditsTrig->width = 200.f;
		creditsTrig->height = 300.f;
		creditsTrig->degrees = 0.f;
		creditsTrig->cornerRad = 25.f;
		creditsTrig->color = CP_Color_Create(10, 0, 10, 0);

		credits = NEWCARDOBJECT;
		if (!credits) return;
		credits->x1 = 700.f;
		credits->y1 = WINDOW_CENTERH - 200.f;
		credits->width = 200.f;
		credits->height = 300.f;
		credits->degrees = 0.f;
		credits->cornerRad = 25.f;
		credits->color = CP_Color_Create(0, 100, 0, 255);

		creditsOGTrig = NEWCARDOBJECT;
		if (!creditsOGTrig) return;
		creditsOGTrig->x1 = 998.f;
		creditsOGTrig->y1 = WINDOW_CENTERH - 200.f;
		creditsOGTrig->width = 50.f;
		creditsOGTrig->height = 290.f;
		creditsOGTrig->degrees = 0.f;
		creditsOGTrig->cornerRad = 25.f;
		creditsOGTrig->color = CP_Color_Create(0, 0, 0, 0);


	
	//exit 
		leaveTrig = NEWCARDOBJECT;
		if (!leaveTrig) return;
		leaveTrig->x1 = 800.f;
		leaveTrig->y1 = WINDOW_CENTERH - 200.f;
		leaveTrig->width = 200.f;
		leaveTrig->height = 300.f;
		leaveTrig->degrees = 0.f;
		leaveTrig->cornerRad = 25.f;
		leaveTrig->color = CP_Color_Create(10, 0, 10, 0);

		leave = NEWCARDOBJECT;
		if (!leave) return;
		leave->x1 = 800.f;
		leave->y1 = WINDOW_CENTERH - 200.f;
		leave->width = 200.f;
		leave->height = 300.f;
		leave->degrees = 0.f;
		leave->cornerRad = 25.f;
		leave->color = CP_Color_Create(100, 0, 100, 255);

		leaveOGTrig = NEWCARDOBJECT;
		if (!leaveOGTrig) return;
		leaveOGTrig->x1 = 1098.f;
		leaveOGTrig->y1 = WINDOW_CENTERH - 200.f;
		leaveOGTrig->width = 50.f;
		leaveOGTrig->height = 290.f;
		leaveOGTrig->degrees = 0.f;
		leaveOGTrig->cornerRad = 25.f;
		//leaveOGTrig->color = CP_Color_Create(0, 0, 0, 255);


	/* { //for flat face
		ogHeight = 300.f; //original height
		cardHeight = ogHeight + 100.f; //bigger trigger size to account for not touching actual card
		changeTrig = ogHeight - 50.f; //smaller than original to not glitch card
	}*/
	
	//for all

		//for start
		originalPos[0] = WINDOW_CENTERH - 200.f;
		posUp[0] = originalPos[0] - 50.f;
		ogHeight[0] = start->height;
		cardHeight[0] = ogHeight[0] + 100.f;
		changeTrig[0] = ogHeight[0] - 50.f;

		//for options
		originalPos[1] = WINDOW_CENTERH - 200.f;
		posUp[1] = originalPos[1] - 50.f;
		ogHeight[1] = start->height;
		cardHeight[1] = ogHeight[1] + 100.f;
		changeTrig[1] = ogHeight[1] - 50.f;

		//for credits
		originalPos[2] = WINDOW_CENTERH - 200.f;
		posUp[2] = originalPos[2] - 50.f;
		ogHeight[2] = start->height;
		cardHeight[2] = ogHeight[2] + 100.f;
		changeTrig[2] = ogHeight[2] - 50.f;

		//for exit
		originalPos[3] = WINDOW_CENTERH - 200.f;
		posUp[3] = originalPos[3] - 50.f;
		ogHeight[3] = start->height;
		cardHeight[3] = ogHeight[3] + 100.f;
		changeTrig[3] = ogHeight[3] - 50.f;




		



	
	scaleCardStraight(startTrig, start, 2,0);
	scaleCardStraight(optionsTrig, options, 2, 1);
	scaleCard(optionsOGTrig, 2);
	scaleCard(creditsOGTrig, 2);
	scaleCard(leaveOGTrig, 2);
	scaleCard(startOGTrig, 2);
	scaleCardStraight(creditsTrig, credits, 2, 2);
	scaleCardStraight(leaveTrig, leave, 2, 3);
	
	for (int i = 0; i < 4; i++)
	{
		checkCard[i] = false;
	}


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

	for (int i = 0; i < 4; i++)
	{
		checkCard[i] = false;
	}

	// check input, update simulation, render etc.
	CP_Graphics_ClearBackground(background);
	drawRect(leaveTrig, 1);
	drawRect(leave, 1);
	drawRect(leaveOGTrig, 1);

	drawRect(creditsTrig, 1);
	drawRect(credits, 1);
	drawRect(creditsOGTrig, 1);

	drawRect(optionsTrig, 1);
	drawRect(options, 1);
	drawRect(optionsOGTrig, 1);


	drawRect(startTrig, 1);
	drawRect(start, 1);
	
	if (checkCollision(start))
	{
		resetCard(options, optionsTrig, optionsOGTrig, 1);
		resetCard(credits, creditsTrig, creditsOGTrig, 2);
		resetCard(leave, leaveTrig, leaveOGTrig, 3);

		checkCard[0] = true;
		for (int i = 1; i < 4; i++)
		{
			checkCard[i] = false;
		}

		
	}
	else if (checkCollision(optionsOGTrig))
	{
		resetCard(start, startTrig, startOGTrig, 0);
		resetCard(credits, creditsTrig, creditsOGTrig, 2);
		resetCard(leave, leaveTrig, leaveOGTrig, 3);
		for (int i = 0; i < 4; i++)
		{
			checkCard[i] = false;
			if (i == 1)
			{
				checkCard[i] = true;
			}
		}

		
	}
	else if (checkCollision(creditsOGTrig))
	{
		resetCard(start, startTrig, startOGTrig, 0);
		resetCard(options, optionsTrig, optionsOGTrig, 1);
		resetCard(leave, leaveTrig, leaveOGTrig, 3);

		for (int i = 0; i < 4; i++)
		{
			checkCard[i] = false;
			if (i == 2)
			{
				checkCard[i] = true;
			}
		}
		
	}
	else if (checkCollision(leaveOGTrig))
	{
		resetCard(start, startTrig, startOGTrig, 0);
		resetCard(options, optionsTrig, optionsOGTrig, 1);
		resetCard(credits, creditsTrig, creditsOGTrig, 2);
		for (int i = 0; i < 4; i++)
		{
			checkCard[i] = false;
			if (i == 3)
			{
				checkCard[i] = true;
			}
		}
		
	}
	else
	{
		resetCard(start,startTrig,startOGTrig, 0);
		resetCard(options,optionsTrig,optionsOGTrig, 1);
		resetCard(credits,creditsTrig,creditsOGTrig, 2);
		resetCard(leave,leaveTrig,leaveOGTrig, 3);
		for (int i = 0; i < 4; i++)
		{
			checkCard[i] = false;
		}
	}

	popUp(startTrig, start, startOGTrig, 0, checkCard[0]);
	popUp(optionsTrig, options, optionsOGTrig, 1, checkCard[1]);
	popUp(creditsTrig, credits, creditsOGTrig, 2, checkCard[2]);
	popUp(leaveTrig, leave, leaveOGTrig, 3, checkCard[3]);

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
	free(optionsOGTrig);
	free(creditsTrig);
	free(credits);
	free(creditsOGTrig);
	free(leaveTrig);
	free(leave);

}
