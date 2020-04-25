/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_emitter_component.h"

#include "entity/ga_entity.h"
#include "framework/ga_frame_params.h"

ga_emitter_component::ga_emitter_component(ga_entity* ent, ga_sim* sim) : ga_component(ent)
{
	_sim = sim;

}

ga_emitter_component::~ga_emitter_component()
{
}

void ga_emitter_component::update(ga_frame_params* params)
{
	ga_entity particle;
	ga_vec3f translate = ga_vec3f({ .1f, 0.0f, 0.0f });
	ga_particle_component particle_move(&particle, translate);
	// ga_cube_component particle_model(&particle, "data/textures/rpi.png");
	_sim->add_entity(&particle);
}
