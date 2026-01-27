#pragma once
#include "gui_object.h"
#include <vector>

#define MAX_Z_INDEX 100

class GUI_Objects_Drawer {
public:
  GUI_Objects_Drawer() {

  };
  ~GUI_Objects_Drawer() {};

  void RegisterDrawGUIObject(GUI_Object *gui_object) {
		objects.push_back(gui_object);
  };

  void Draw() {
		for(auto *obj : objects) {
			obj->Draw();
		}
  };

private:
	std::vector<GUI_Object*> objects = std::vector<GUI_Object*>();
};
