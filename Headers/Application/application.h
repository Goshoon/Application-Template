#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"

#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class Application
{
public:
	Application();
	~Application();
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool done = false;
	bool mbLeft = false;
	bool mbRight = false;

	std::vector<SDL_Texture*> textures;

	void Display();
	void Input();
	void LoadTexture(const char* fileDir);
private:
	void InputReleased(SDL_Event* event);
	void InputPressed(SDL_Event* event);
};