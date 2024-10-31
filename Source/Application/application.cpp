#include "application.h"
#include <iostream>
void Application::LoadTexture(const char* fileDir)
{
	//SDL_Texture* _texture = IMG_LoadTexture(renderer, fileDi);
	textures.emplace_back(IMG_LoadTexture(renderer, fileDir));
}

Application::Application()
{
	window = SDL_CreateWindow(
		"Application", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);

	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED 
	);

	done = false;
	mbLeft = false;
	mbRight = false;
}

Application::~Application()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Application::Display()
{
	ImGui::Render();
	SDL_RenderClear( renderer );
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
}

void Application::DrawEverything()
{
	SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
	SDL_RenderPresent(renderer);
}

void Application::Input() /* Teclas e interacciones con la ventana */
{
	SDL_Event event;
	while ( SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				done = true;
			break;
			case SDL_KEYDOWN:
				InputPressed(&event);
			break;
			case SDL_KEYUP:
				InputReleased(&event);
			break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
				{
				case SDL_BUTTON_LEFT:
					mbLeft = true;
				break;
				case SDL_BUTTON_RIGHT:
					mbRight = true;
				break;
				}

			break;
			case SDL_MOUSEBUTTONUP:
				mbLeft = false;
				mbRight = false;
			break;
        }
    }
}

void Application::InputReleased(SDL_Event* event)
{
	switch (event->key.keysym.sym)
	{
		case SDLK_ESCAPE:
			done = true;
		break;
		case SDLK_w:
			std::cout << "hola";
		break;

	}
}

void Application::InputPressed(SDL_Event* event)
{
	switch (event->key.keysym.sym)
	{

	}
}

void Application::DrawRectangle(int x, int y, int width, int height, SDL_Color color)
{
    // Establecer el color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Crear area donde se va a dibujar
    SDL_Rect squareRect = { x, y, width, height }; // { x, y, ancho, alto }

    // Dibujar el rectangulo en el area
    SDL_RenderFillRect(renderer, &squareRect);

    // Resetear el color a negro
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // color Default
}