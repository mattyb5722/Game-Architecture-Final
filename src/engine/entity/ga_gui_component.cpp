/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_gui_component.h"

#include "entity/ga_entity.h"
#include "framework/ga_frame_params.h"

#include "entity/ga_emitter_component.h"

ga_gui_component::ga_gui_component(ga_entity* ent, ga_entity* emitter) : ga_component(ent)
{	
	_emitter = emitter;
	_button_phase = 0;
}

ga_gui_component::~ga_gui_component()
{
}

void ga_gui_component::update(ga_frame_params* params)
{
	ga_emitter_component* emitter_component = (ga_emitter_component*)_emitter->get_component(0);

	ga_button Movement("Movement", 20.0f, 20.0f, params);
	ga_button Edit_System("Edit System", 100.0f, 20.0f, params);
	ga_button Edit_Particle_System("Edit Particle System", 205.0f, 20.0f, params);

	if (Movement.get_clicked(params)) {
		_button_phase == 1 ? _button_phase = 0 : _button_phase = 1;
	}
	else if (Edit_System.get_clicked(params)) {
		_button_phase == 2 ? _button_phase = 0 : _button_phase = 2;
	}
	else if (Edit_Particle_System.get_clicked(params)) {
		_button_phase == 3 ? _button_phase = 0 : _button_phase = 3;
	}

	if (_button_phase == 1) {
		if (ga_button("X++", 20.0f, 60.0f, params).get_clicked(params)) {
			_emitter->translate(ga_vec3f({ 1.0f, 0.0f, 0.0f }));
		}
		else if (ga_button("X--", 20.0f, 80.0f, params).get_clicked(params)) {
			_emitter->translate(ga_vec3f({ -1.0f, 0.0f, 0.0f }));
		}
		else if (ga_button("Y++", 20.0f, 100.0f, params).get_clicked(params)) {
			_emitter->translate(ga_vec3f({ 0.0f, 1.0f, 0.0f }));
		}
		else if (ga_button("Y--", 20.0f, 120.0f, params).get_clicked(params)) {
			_emitter->translate(ga_vec3f({ 0.0f, -1.0f, 0.0f }));
		}
		else if (ga_button("Z++", 20.0f, 140.0f, params).get_clicked(params)) {
			_emitter->translate(ga_vec3f({ 0.0f, 0.0f, 1.0f }));
		}
		else if (ga_button("Z--", 20.0f, 160.0f, params).get_clicked(params)) {
			_emitter->translate(ga_vec3f({ 0.0f, 0.0f, -1.0f }));
		}
	}
	else if (_button_phase == 2) {
		if (ga_button("Sphere", 20.0f, 60.0f, params).get_clicked(params)) {
			emitter_component->setShape("Sphere");
		}
		else if (ga_button("Dome", 20.0f, 80.0f, params).get_clicked(params)) {
			emitter_component->setShape("Dome");
		}
		else if (ga_button("Cone", 20.0f, 100.0f, params).get_clicked(params)) {
			emitter_component->setShape("Cone");
		}
		else if (ga_button("Plane", 20.0f, 120.0f, params).get_clicked(params)) {
			emitter_component->setShape("Plane");
		}
		else if (ga_button("Initial Velocity++", 20.0f, 140.0f, params).get_clicked(params)) {
			emitter_component->increment_Initial_Velocity();
		}
		else if (ga_button("Initial Velocity--", 20.0f, 160.0f, params).get_clicked(params)) {
			emitter_component->decrement_Initial_Velocity();
		}
		else if (ga_button("Acceleration++", 20.0f, 180.0f, params).get_clicked(params)) {
			emitter_component->increase_acceleration();
		}
		else if (ga_button("Acceleration--", 20.0f, 200.0f, params).get_clicked(params)) {
			emitter_component->decrease_acceleration();
		}
		else if (ga_button("Energy++", 20.0f, 220.0f, params).get_clicked(params)) {
			emitter_component->increase_energy();
		}
		else if (ga_button("Energy--", 20.0f, 240.0f, params).get_clicked(params)) {
			emitter_component->decrease_energy();
		}
	}
	else if (_button_phase == 3) {
		if (ga_button("Image++", 20.0f, 60.0f, params).get_clicked(params)) {
			emitter_component->increment_Texture();
		}
		else if (ga_button("Image--", 20.0f, 80.0f, params).get_clicked(params)) {
			emitter_component->decrement_Texture();
		}
	}
	
}
