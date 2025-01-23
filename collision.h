
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
//void popUpFlat(cardObject* trig, cardObject* card);
void resetCard(cardObject* card, cardObject* trig, cardObject* OG, int i);
void popUp(cardObject* trig, cardObject* card,cardObject* ogTrig, int i, bool hovering);
void scaleCardStraight(cardObject* trig, cardObject* card, float scale, int i);
void scaleCard(cardObject* card, float scale);
//void scaleCardDiagonal(cardObject* trig, cardObject* card, float scale, int i );
