//---------------------------------------------------------
// file:	menu.h
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	header file for menu gamestate
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//--------------------------------------------------------
#pragma once
#include <stdlib.h>

typedef struct cardObject
{
	CP_Color color;
	

	float x1, x2, y1, y2;
	float width, height;
	float degrees;
	float cornerRad;

}cardObject;

#define NEWCARDOBJECT (cardObject*)malloc(sizeof(struct cardObject))

void menu_init(void);
void menu_update(void);
void menu_exit(void);
