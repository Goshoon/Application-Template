#pragma once
#include "SDL.h"
#include "SDL_Image.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class Screen
{
public:
	Screen();
	~Screen();

	void Update();
	void Render();
};