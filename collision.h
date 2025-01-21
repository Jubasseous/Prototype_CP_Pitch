
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
void popUp(cardObject* trig, cardObject* card);
