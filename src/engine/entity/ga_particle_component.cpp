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
	_energy = 1.0f;
	set_wind();
}

ga_particle_component::~ga_particle_component()
{
}

float randomNumber(float HI, float LO) {
	return LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}

void ga_particle_component::update(ga_frame_params* params)
{
	_translation.scale(_acceleration);
	float x = randomNumber(1.0 * _energy * _translation.axes[0], -1.0 * _energy * _translation.axes[0]);
	float y = randomNumber(1.0 * _energy * _translation.axes[1], -1.0 * _energy * _translation.axes[1]);
	float z = randomNumber(1.0 * _energy * _translation.axes[2], -1.0 * _energy * _translation.axes[2]);

	// _translation = ga_vec3f({ 1.0f, 0.0f, 0.0f });
	// _translation += ga_vec3f({ x, y, z });
	// printf("_translation: x: %f, y: %f, z: %f\n", _translation.axes[0], _translation.axes[1], _translation.axes[2]);
	// printf("Temp: x: %f, y: %f, z: %f\n\n", temp.axes[0], temp.axes[1], temp.axes[2]);
	_ent->translate(_translation + ga_vec3f({ x, y, z }) + _wind);
}

void ga_particle_component::addToScene(ga_mat4f start, ga_vec3f translation, float acceleration, float energy)
{
	_translation = translation;
	get_entity()->set_transform(start);
	_acceleration = acceleration;
	_energy = energy;
	set_wind();
}

void ga_particle_component::set_wind() {
	float x = randomNumber(1.5 * _translation.mag(), -1.5 * _translation.mag());
	float y = randomNumber(1.5 * _translation.mag(), -1.5 * _translation.mag());
	float z = randomNumber(1.5 * _translation.mag(), -1.5 * _translation.mag());
	_wind = ga_vec3f({ x, y, z });
}
