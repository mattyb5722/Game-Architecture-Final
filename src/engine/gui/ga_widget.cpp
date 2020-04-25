/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_widget.h"

void ga_widget::draw_outline(ga_frame_params* params, const ga_vec2f& min, const ga_vec2f max, const ga_vec3f& color, float offset) {

	float upper_left_x = min.x;
	float lower_right_x = max.x;

	float upper_left_y = min.y;
	float lower_right_y = max.y;
	
	ga_dynamic_drawcall drawcall;

	drawcall._positions.push_back({ upper_left_x, upper_left_y, 0.0f });
	drawcall._positions.push_back({ lower_right_x, upper_left_y, 0.0f });
	drawcall._positions.push_back({ lower_right_x, lower_right_y, 0.0f });
	drawcall._positions.push_back({ upper_left_x, lower_right_y, 0.0f });

	drawcall._indices.push_back(0);
	drawcall._indices.push_back(1);
	drawcall._indices.push_back(1);
	drawcall._indices.push_back(2);
	drawcall._indices.push_back(2);
	drawcall._indices.push_back(3);
	drawcall._indices.push_back(3);
	drawcall._indices.push_back(0);

	drawcall._color = color;
	drawcall._draw_mode = GL_LINES;
	drawcall._transform.make_identity();
	drawcall._material = nullptr;

	while (params->_gui_drawcall_lock.test_and_set(std::memory_order_acquire)) {}
	params->_gui_drawcalls.push_back(drawcall);
	params->_gui_drawcall_lock.clear(std::memory_order_release);
}

void ga_widget::draw_check(ga_frame_params* params, const ga_vec2f& min, const ga_vec2f max, const ga_vec3f& color, float offset) {

	float upper_left_x = min.x;
	float lower_right_x = max.x;

	float upper_left_y = min.y;
	float lower_right_y = max.y;

	ga_dynamic_drawcall drawcall;

	drawcall._positions.push_back({ upper_left_x, upper_left_y, 0.0f });
	drawcall._positions.push_back({ lower_right_x, upper_left_y, 0.0f });
	drawcall._positions.push_back({ lower_right_x, lower_right_y, 0.0f });
	drawcall._positions.push_back({ upper_left_x, lower_right_y, 0.0f });

	drawcall._indices.push_back(0);
	drawcall._indices.push_back(2);
	drawcall._indices.push_back(1);
	drawcall._indices.push_back(3);

	drawcall._color = color;
	drawcall._draw_mode = GL_LINES;
	drawcall._transform.make_identity();
	drawcall._material = nullptr;

	while (params->_gui_drawcall_lock.test_and_set(std::memory_order_acquire)) {}
	params->_gui_drawcalls.push_back(drawcall);
	params->_gui_drawcall_lock.clear(std::memory_order_release);
}


void ga_widget::draw_fill(ga_frame_params* params, const ga_vec2f& min, const ga_vec2f max, const ga_vec3f& color, float offset) {

	float upper_left_x = min.x;
	float lower_right_x = max.x;

	float upper_left_y = min.y;
	float lower_right_y = max.y;

	ga_dynamic_drawcall drawcall;

	drawcall._positions.push_back({ upper_left_x, upper_left_y, 0.0f });
	drawcall._positions.push_back({ lower_right_x, upper_left_y, 0.0f });
	drawcall._positions.push_back({ lower_right_x, lower_right_y, 0.0f });
	drawcall._positions.push_back({ upper_left_x, lower_right_y, 0.0f });

	drawcall._indices.push_back(0);
	drawcall._indices.push_back(1);
	drawcall._indices.push_back(1);
	drawcall._indices.push_back(2);
	drawcall._indices.push_back(2);
	drawcall._indices.push_back(3);
	drawcall._indices.push_back(3);
	drawcall._indices.push_back(0);

	drawcall._color = color;
	drawcall._draw_mode = GL_TRIANGLES;
	drawcall._transform.make_identity();
	drawcall._material = nullptr;

	while (params->_gui_drawcall_lock.test_and_set(std::memory_order_acquire)) {}
	params->_gui_drawcalls.push_back(drawcall);
	params->_gui_drawcall_lock.clear(std::memory_order_release);
}

bool ga_widget::get_hover(const ga_frame_params* params, ga_vec2f _min, ga_vec2f _max) const
{
	return
		params->_mouse_x >= _min.x &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x &&
		params->_mouse_y <= _max.y;
}
