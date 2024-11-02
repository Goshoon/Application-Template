#include "sceneExample.h"

sceneExample::sceneExample()
{
	std::cout << "Created!";
}

sceneExample::~sceneExample()
{

}

void sceneExample::Update()
{
	{
		ImGui::Begin("Ventana de ejemplo :3");
		ImGui::Text(":3333");
		ImGui::End();
	}
}

void sceneExample::Render()
{
	app->DrawRectangle(5, 5, 250, 250, {255, 255, 0, 255});
}