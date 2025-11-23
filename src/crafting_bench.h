#pragma once

#include "object.h"
#include "raylib.h"

class Crafting_Bench : public Object {

public:
	Crafting_Bench() {
		Image img = LoadImage("../assets/crafting-bench.png");
		ImageResize(&img, 48, 96);
		tex = LoadTextureFromImage(img);
		rect.width = 48;
		rect.height = 96;
	};
	~Crafting_Bench() {};
	void Draw() override;

private:
	Texture2D tex;
};
