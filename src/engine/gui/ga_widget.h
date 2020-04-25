#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "math/ga_vec3f.h"
#include "math/ga_vec2f.h"
#include "framework\ga_frame_params.h"

/*
** Base class for GUI widgets.
*/
class ga_widget
{
public:
	void draw_outline(ga_frame_params* params, const ga_vec2f& min, const ga_vec2f max, const ga_vec3f& color, float offset);
	void draw_fill(ga_frame_params* params, const ga_vec2f& min, const ga_vec2f max, const ga_vec3f& color, float offset);
	void draw_check(ga_frame_params* params, const ga_vec2f& min, const ga_vec2f max, const ga_vec3f& color, float offset);

	bool ga_widget::get_hover(const ga_frame_params* params, ga_vec2f _min, ga_vec2f _max) const;

	const ga_vec3f k_button_color = { .5f, .5f, .5f };
	const ga_vec3f k_button_hover_color = { .75f, .75f, .75f };
	const ga_vec3f k_button_press_color = { .4f, .5f, .2f };
	const ga_vec3f k_text_color = { .5f, .5f, .5f };

	const float k_checkbox_offset = 15.0f;
	const float k_button_offset = 2.5f;

private:

};
