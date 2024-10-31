#include "main.h"
using std::cout, std::cin, std::shared_ptr, std::unique_ptr;

unique_ptr<Application> app (new Application); /* Crear una instancia de la aplicacion (ventana + render) */
int main(int argc, char* argv[])
{
	// Inicializar SDL2 & ImGui
	Inititialize();

	// Crear escena inicial
	Screen currentScreen = Screen();

	while(!app->done) /* Ciclo loop */
	{
		app->Input(); /* Detectar teclas e interacciones con la ventana */

		ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        currentScreen.Update(); /* Metodo de crear botones e interacciones de la escena actual */
        currentScreen.Render(); /* Metodo de mostrar elementos como imagenes u efectos */

		app->Display(); /* Mostrar interfaces y Actualizar pantalla */
		app->DrawRectangle(5, 5, 250, 250, {255, 255, 0, 255});
		app->DrawEverything();
	}

	// Cerrar dependencias y limpiar memoria
	Quit();
	return 0;
}