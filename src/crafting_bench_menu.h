#pragma once
#include "crafting_bench_menu.h"
#include "gui_object.h"
#include "raylib.h"

class Crafting_Bench_Menu : public GUI_Object {

public:
	Crafting_Bench_Menu(int width, int height) {
		rect.x = 20;
		rect.y = 20;
		rect.width = width;
		rect.height = height;
	};
	~Crafting_Bench_Menu() {};


	void ShowMenu() { show_menu = true; };
	void HideMenu() { show_menu = false; };

	void Draw() override;
	

	bool show_menu = false;

private:
};
