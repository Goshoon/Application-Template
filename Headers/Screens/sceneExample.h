#pragma once
#include "screen.h"
	class sceneExample : public Screen
	{
	public:
		sceneExample();
		~sceneExample();

		void Update() override;
		void Render() override;
	};