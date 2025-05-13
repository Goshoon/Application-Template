#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class Application
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

	std::unordered_map<std::string, SDL_Texture*> images;
	std::unordered_map<std::string, Mix_Music*> sounds;

	bool done = false;
	bool mbLeft = false;
	bool mbRight = false;
  static Application& GetInstance()
  {
    static Application instance;
    return instance;
  }

	void Input();
  /* Load Assets */
	void AddTexture(const std::string& ID, const char* fileDir);
	SDL_Texture* GetTexture(const std::string& ID);
	void AddSound(const std::string& ID, const char* fileDir);
	Mix_Music* GetSound(const std::string& ID);

	void DrawRectangle(int x, int y, int width, int height, SDL_Color color);
	void RenderImage( SDL_Texture* image, int x, int y );
	void RenderImage( SDL_Texture* image, int x, int y, int w, int h );
	void Display();
	void DrawEverything();
private:
	Application();
	~Application();

  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;

	void InputReleased(SDL_Event* event);
	void InputPressed(SDL_Event* event);
};
