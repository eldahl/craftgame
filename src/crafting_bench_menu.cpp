#include "crafting_bench_menu.h"
#include "raylib.h"

void Crafting_Bench_Menu::Draw() {
  if (show_menu) {
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, GRAY);
    DrawText("Crafting Bench Menu", rect.x + 10, rect.y + 10, 18, RED);
  }
}
