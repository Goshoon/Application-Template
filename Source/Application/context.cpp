#include "context.h"

void Inititialize() // Initialoze SDL y SDL_Image
{
  Application& app = Application::GetInstance();
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG;

	// Inicializar Dear ImGui
	IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

  ImGui::StyleColorsDark(); // Theme

  // Setup Platform/Renderer backends
  ImGui_ImplSDL2_InitForSDLRenderer(app.window, app.renderer);
  ImGui_ImplSDLRenderer2_Init(app.renderer);
}
void Quit() // Clenup extermal libraries
{
  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
    
	SDL_Quit();
}
