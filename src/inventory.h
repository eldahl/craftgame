#pragma once

#include "gui_object.h"

class Inventory : public GUI_Object {

public:
	Inventory(int width, int height) {
		rect.x = 800 - width - 20;
		rect.y = 20;
		rect.width = width;
		rect.height = height;
	};
	~Inventory() {};


	void ShowMenu() { show_menu = true; };
	void HideMenu() { show_menu = false; };

	void Draw() override;
	

	bool show_menu = false;

private:

};
