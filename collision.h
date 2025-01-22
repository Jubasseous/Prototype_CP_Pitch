
//---------------------------------------------------------
// file:	collision.h
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

#include <stdbool.h>
#include "drawinglib.h"

int checkCollision(cardObject* card);
void popUpFlat(cardObject* trig, cardObject* card);
void popUpDiagonal(cardObject* trig, cardObject* card, int i);
void scaleCardStraight(cardObject* trig, cardObject* card, float scale);
void scaleCardDiagonal(cardObject* trig, cardObject* card, float scale, int i );
