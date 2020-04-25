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

ga_particle_component::ga_particle_component(ga_entity* ent, ga_vec3f translation) : ga_component(ent)
{
	_ent = ent;
	_translation = translation;
}

ga_particle_component::~ga_particle_component()
{
}

void ga_particle_component::update(ga_frame_params* params)
{
	_ent->translate(_translation);
}
