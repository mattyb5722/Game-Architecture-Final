/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_lua_component.h"

#include "entity/ga_entity.h"
#include "framework/ga_frame_params.h"

#include <lua.hpp>

static int frame_params_get_input_left(lua_State *L) {
	ga_frame_params* params = (ga_frame_params*)lua_touserdata(L, -1);
	if (params->_button_mask == 16384) {			// J
		lua_pushboolean(L, true);
	}
	else {
		lua_pushboolean(L, false);
	}
	return 1;
}

static int frame_params_get_input_right(lua_State *L) {
	ga_frame_params* params = (ga_frame_params*)lua_touserdata(L, -1);
	if (params->_button_mask == 65536) {			// L
		lua_pushboolean(L, true);
	}
	else {
		lua_pushboolean(L, false);
	}
	return 1;
}

static int component_get_entity(lua_State *L) {
	ga_lua_component* component = (ga_lua_component*)lua_touserdata(L, -1);
	lua_pushlightuserdata(L, component->get_entity());
	return 1;
}

static int entity_translate(lua_State *L) {
	ga_entity* entity = (ga_entity*)lua_touserdata(L, -4);
	float x = (float)lua_tonumber(L, -3);
	float y = (float)lua_tonumber(L, -2);
	float z = (float)lua_tonumber(L, -1);
	entity->translate(ga_vec3f({ x, y, z }));
	return 0;
}


ga_lua_component::ga_lua_component(ga_entity* ent, const char* path) : ga_component(ent)
{
	_lua = luaL_newstate();
	luaL_openlibs(_lua);

	extern char g_root_path[256];
	std::string fullpath = g_root_path;
	fullpath += path;

	int status = luaL_loadfile(_lua, fullpath.c_str());
	if (status)
	{
		// std::cerr << "Failed to load script " << path << ": " << lua_tostring(lua, -1);
		lua_close(_lua);
	}

	lua_pcall(_lua, 0, 1, 0);

	lua_register(_lua, "frame_params_get_input_left", frame_params_get_input_left);
	lua_register(_lua, "frame_params_get_input_right", frame_params_get_input_right);
	lua_register(_lua, "component_get_entity", component_get_entity);
	lua_register(_lua, "entity_translate", entity_translate);
}

ga_lua_component::~ga_lua_component()
{
	// TODO: Homework 7
}

void ga_lua_component::update(ga_frame_params* params)
{
	// TODO: Homework 7
	lua_getglobal(_lua, "update");			// function to be called
	lua_pushlightuserdata(_lua, this);		// component
	lua_pushlightuserdata(_lua, params);	// frame_params

	if (lua_pcall(_lua, 2, 0, 0) != 0) {
		printf("error running function `f': %s\n", lua_tostring(_lua, -1));
		lua_pop(_lua, 1);
	}
}
