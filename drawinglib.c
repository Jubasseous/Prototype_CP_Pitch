
#include "cprocessing.h"
#include "menu.h"
#include <stdbool.h>
#include "drawinglib.h"

void drawRect(cardObject* rectObject, bool state)
{
	if (!rectObject) return;

	// Degree correction if degrees is over 360.f.
	if (rectObject->degrees > 360.f)
	{
		rectObject->degrees = rectObject->degrees - 360.f;
	}

	if (state)
	{
		CP_Settings_Fill(rectObject->color);
		CP_Graphics_DrawRectAdvanced(
			rectObject->x1,
			rectObject->y1,
			rectObject->width,
			rectObject->height,
			rectObject->degrees,
			rectObject->cornerRad
		);
		// Always clear the stroke and fill colors once the object has been drawn.
		CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 250));
		//CP_Settings_NoStroke();
		CP_Settings_NoFill();
	}

}