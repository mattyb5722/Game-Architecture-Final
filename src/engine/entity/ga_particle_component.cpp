/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_particle_component.h"
#include "entity/ga_entity.h"

ga_particle_component::ga_particle_component(ga_entity* ent) : ga_component(ent)
{
	_ent = ent;
	_translation = ga_vec3f({ 0.0f, 0.0f, 0.0f });
	_acceleration = 1.0f;
}

ga_particle_component::~ga_particle_component()
{
}

void ga_particle_component::update(ga_frame_params* params)
{
	_translation.scale(_acceleration);
	_ent->translate(_translation);
}

void ga_particle_component::addToScene(ga_mat4f start, ga_vec3f translation, float acceleration)
{
	_translation = translation;
	get_entity()->set_transform(start);
	_acceleration = acceleration;
}
