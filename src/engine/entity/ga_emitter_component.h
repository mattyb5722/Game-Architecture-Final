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
#include "graphics/ga_2D_sprite_component.h"

/*
** A component whose logic is implemented in LUA.
*/
class ga_emitter_component : public ga_component
{
public:
	ga_emitter_component(class ga_entity* ent);
	virtual ~ga_emitter_component();

	virtual void update(struct ga_frame_params* params) override;

	void increment_Texture();
	void decrement_Texture();
	ga_vec3f determine_particle_translte();

	void setShape(std::string particle_shape) { _particle_shape = particle_shape; };

	void increment_Initial_Velocity() { _particle_speed += 0.01f; }
	void decrement_Initial_Velocity() {
		_particle_speed -= 0.01f;
		if (_particle_speed < 0.0f) {
			_particle_speed = 0.0f;
		};
	}

	void increase_acceleration() { _particle_acceleration += .01f; }
	void decrease_acceleration() { _particle_acceleration -= .01f; }

private:
	int _particle_index;
	float _particle_speed;
	float _particle_acceleration;
	std::string _particle_shape;

	int _texture_index;
	std::vector<class ga_material*> _materials;
};
