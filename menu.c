
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

CP_Color background;
CP_Image xCard;
CP_Image oCard;
cardObject* startTrig;
//cardObject start;
//cardObject optionsTrig;
//cardObject options;
//cardObject creditTrig;
//cardObject credit;
//cardObject exitTrig;
//cardObject exit;
float posUp;
float posDown;
int Onstate;
int Offstate;
float originalPos;

#define WINDOW_CENTERW CP_System_GetWindowWidth()/2.f;
#define WINDOW_CENTERH CP_System_GetWindowHeight()/2.f;



// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void menu_init(void)
{
	CP_System_Fullscreen();

	background = CP_Color_Create(10, 10, 10, 255);
	CP_Graphics_ClearBackground(background);

	//CP_Settings_RectMode(CP_POSITION_CENTER); 
	CP_Settings_RectMode(CP_POSITION_CORNER);

	startTrig = NEWCARDOBJECT;
	if (!startTrig) return;
	startTrig->x1 = WINDOW_CENTERW - 400.f;
	startTrig->y1 = WINDOW_CENTERH - 200.f;
	startTrig->width = 250.f;
	startTrig->height = 500.f;
	startTrig->degrees = 0.f;
	startTrig->color = CP_Color_Create(0, 150, 100, 255);

	originalPos = WINDOW_CENTERH - 200.f;;
	posUp = originalPos - 100.f;


	

	
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void menu_update(void)
{
	
	// check input, update simulation, render etc.
	if (checkCollision(startTrig))
	{

		startTrig->color = CP_Color_Create(500, 300, 150, 255);
		startTrig->y1 = posUp;
	}
	else
	{
		
		startTrig->color = CP_Color_Create(0, 150, 100, 255);
		startTrig->y1 = originalPos;
	}

	//drawRect(startTrig, 1);
	






}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void menu_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
	
	free(startTrig);
}
