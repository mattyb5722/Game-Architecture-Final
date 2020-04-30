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

/*
** A component whose logic is implemented in LUA.
*/
class ga_particle_component : public ga_component
{
public:
	ga_particle_component(class ga_entity* ent);
	virtual ~ga_particle_component();

	virtual void update(struct ga_frame_params* params) override;
	void addToScene(ga_mat4f start, ga_vec3f translation, float acceleration, float energy);

	void set_wind();

private:
	ga_entity* _ent;

	ga_vec3f _translation;
	float _acceleration;
	float _energy;
	ga_vec3f _wind;
};
