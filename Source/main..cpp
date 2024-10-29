#include "main.h"
using std::cout, std::cin, std::shared_ptr, std::unique_ptr;

unique_ptr<Application> app (new Application);
int main(int argc, char* argv[])
{
	//Screen currentScreen = Screen();
	// Inicializar SDL2
	Inititialize();
	cout << "hola";

	while(!app->done) /* Ciclo loop */
	{
		app->Input(); /* Detectar teclas e interacciones con la ventana */

		ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        
        {
        	ImGui::Begin("Hello, world!");
 			ImGui::Text(":3");
 			if (ImGui::Button("boton cagao"))
 			{
 				cout << "caca";
 			}
        	ImGui::End();
        }
        

		app->Display(); /* Mostrar interfaces y Actualizar pantalla */
	}

	Quit();
	return 0;
}