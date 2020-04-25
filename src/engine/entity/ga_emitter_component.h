#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_component.h"
#include "framework/ga_sim.h"

#include "ga_particle_component.h"
#include "graphics/ga_cube_component.h"

/*
** A component whose logic is implemented in LUA.
*/
class ga_emitter_component : public ga_component
{
public:
	ga_emitter_component(class ga_entity* ent, ga_sim* sim);
	virtual ~ga_emitter_component();

	virtual void update(struct ga_frame_params* params) override;

private:
	ga_sim* _sim;
};
