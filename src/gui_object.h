#pragma once
#include "raylib.h"

class GUI_Object {
public:
  GUI_Object() {
    rect.x = 0;
    rect.y = 0;
    rect.width = 0;
    rect.height = 0;
  };
  ~GUI_Object() {};

  Rectangle rect;
  int z_index = 0;

  virtual void Draw() {
		DrawRectangle(rect.x, rect.y, rect.width, rect.height, GRAY);
		DrawText("GUI_Object | Draw override not implemented.", rect.x + 10, rect.y + 10, 12, RED);
  };

private:
};

