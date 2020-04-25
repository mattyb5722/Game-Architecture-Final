/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_checkbox.h"

#include "framework/ga_frame_params.h"
#include "ga_font.h"

ga_checkbox::ga_checkbox(bool state, const char* text, float x, float y, ga_frame_params* params)
{
	ga_vec2f text_min, text_max;						// Size of text
	extern ga_font* g_font;								// Pointer to font class

	// Print given string at given position
	g_font->print(params, text, x + k_checkbox_offset, y, k_text_color, &text_min, &text_max);

	// Find position of checkbox
	_min = { x, text_min.y };
	_max = { x + (text_max.y - text_min.y), text_max.y };

	// Draw Checkbox
	draw_outline(params, _min, _max, get_hover(params, _min, _max) ? k_button_hover_color : k_button_color, 0.0f);

	// If the checkbox has been clicked
	if (state) {
		// Draw an X over the checkbox
		draw_check(params, _min, _max, k_button_press_color, 0.0f);
	}
}

ga_checkbox::~ga_checkbox()
{
}

bool ga_checkbox::get_clicked(const ga_frame_params* params) const
{
	return 
		params->_mouse_click_mask != 0 &&
		params->_mouse_x >= _min.x &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x &&
		params->_mouse_y <= _max.y;
}
