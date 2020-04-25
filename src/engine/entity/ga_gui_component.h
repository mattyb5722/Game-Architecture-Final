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

#include "gui/ga_button.h"
#include "gui/ga_checkbox.h"
#include "gui/ga_label.h"

/*
** A component whose logic is implemented in LUA.
*/
class ga_gui_component : public ga_component
{
public:
	ga_gui_component(class ga_entity* ent, ga_entity* emitter);
	virtual ~ga_gui_component();

	virtual void update(struct ga_frame_params* params) override;

private:
	ga_entity* _emitter;
	// ga_emitter_component* _emitter_component;
};
