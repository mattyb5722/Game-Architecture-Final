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

#include "graphics/ga_material.h"


ga_emitter_component::ga_emitter_component(ga_entity* ent) : ga_component(ent)
{
	_particle_index = 0;
	_particle_speed = .05f;
	_particle_acceleration = 1.0f;
	_particle_shape = "Sphere";
	_particle_size = 1.0f;
	_particle_energy = 1.0f;

	_texture_index = 0;

	for (int i = 1; i <= 5; i++) {
		std::string texture_file = "data/textures/Flame_" + std::to_string(i) + ".png";
		class ga_material* material = new ga_unlit_texture_material(texture_file.c_str());
		material->init();
		_materials.push_back(material);
	}
	for (int i = 1; i <= 16; i++) {
		std::string texture_file = "data/textures/Dust_" + std::to_string(i) + ".png";
		class ga_material* material = new ga_unlit_texture_material(texture_file.c_str());
		material->init();
		_materials.push_back(material);
	}
}

ga_emitter_component::~ga_emitter_component()
{
}

ga_vec3f ga_emitter_component::determine_particle_translte() {
	float x, y, z;
	if (_particle_shape.compare("Sphere")== 0) {
		float LO = -1 * _particle_speed;
		float HI = 1 * _particle_speed;
		x = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
		y = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
		z = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
	}
	else if (_particle_shape.compare("Dome") == 0) {
		float LO = -1 * _particle_speed;
		float HI = 1 * _particle_speed;
		x = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
		y = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - 0)));
		z = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));

		LO = .1 * _particle_speed;
		y = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
	}
	else if (_particle_shape.compare("Cone") == 0) {
		float LO = -.25f * _particle_speed;
		float HI = .25f * _particle_speed;
		x = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
		z = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));

		LO = 0;
		HI = 1 * _particle_speed;
		y = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));

	}
	else if (_particle_shape.compare("Plane") == 0) {
		float LO = -1 * _particle_speed;
		float HI = 1 * _particle_speed;
		x = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
		z = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));

		y = 0.0f;
	}
	return ga_vec3f({ x, y, z });
}

void ga_emitter_component::update(ga_frame_params* params)
{
	extern std::vector<ga_entity*> particles;
	
	ga_particle_component* particle = (ga_particle_component*)particles[_particle_index]->get_component(0);
	particle->addToScene(get_entity()->get_transform(), determine_particle_translte(), _particle_acceleration, _particle_energy);

	ga_2D_sprite_component* sprite = (ga_2D_sprite_component*)particles[_particle_index]->get_component(1);
	sprite->setTextures(_materials[_texture_index], _particle_size);

	_particle_index++;
	if (_particle_index >= particles.size()) {
		_particle_index = 0;
	}
}

void ga_emitter_component::increment_Texture() {
	_texture_index++;
	if (_texture_index >= _materials.size()) {
		_texture_index = _materials.size() - 1;
	}
}

void ga_emitter_component::decrement_Texture() {
	_texture_index--;
	if (_texture_index < 0) {
		_texture_index = 0;
	}
}

void ga_emitter_component::increase_acceleration()
{
	_particle_acceleration += .005f;
}

void ga_emitter_component::decrease_acceleration()
{
	_particle_acceleration -= .005f;
	if (_particle_acceleration < 0.0f) {
		_particle_acceleration = 0.0f;
	}
}

void ga_emitter_component::increase_size()
{
	_particle_size += 0.1f;
}

void ga_emitter_component::decrease_size()
{
	_particle_size -= 0.5f;
	if (_particle_size < 0.1f) {
		_particle_size = 0.1f;
	}
}

void ga_emitter_component::increase_energy()
{
	_particle_energy += 0.1f;
}

void ga_emitter_component::decrease_energy()
{
	_particle_energy -= 0.1f;
	if (_particle_size < 0.1f) {
		_particle_size = 0.1f;
	}
}
