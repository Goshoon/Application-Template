#include "screen.h"

Screen::Screen()
{

}

Screen::~Screen()
{

}

void Screen::Update()
{
	{
        ImGui::Begin("Hello, world!");
 		ImGui::Text(":3");
        ImGui::End();
	}
}

void Screen::Render()
{

}