#pragma once

#include "object.h"
#include "raylib.h"
#include "crafting_bench_menu.h"

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
	
	Crafting_Bench_Menu menu = Crafting_Bench_Menu(240, 400);

private:
	Texture2D tex;

};
