/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_button.h"

#include "framework/ga_frame_params.h"
#include "ga_font.h"

ga_button::ga_button(const char* text, float x, float y, ga_frame_params* params)
{
	ga_vec2f text_min, text_max;						// Size of text
	extern ga_font* g_font;								// Pointer to font class

	// Print given string at given position
	g_font->print(params, text, x, y, k_text_color, &text_min, &text_max);

	// Find position of button
	_min = { x - k_button_offset, text_min.y - k_button_offset };
	_max = { x + (text_max.x - text_min.x) + k_button_offset, text_max.y + k_button_offset };
	
	// Find position of button
	draw_outline(params, _min, _max, get_hover(params, _min, _max) ? k_button_hover_color : k_button_color, 0.0f);
}

ga_button::~ga_button()
{
}

bool ga_button::get_clicked(const ga_frame_params* params) const
{
	return
		params->_mouse_click_mask != 0 &&
		params->_mouse_x >= _min.x &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x &&
		params->_mouse_y <= _max.y;
}
