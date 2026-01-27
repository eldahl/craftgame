#include "inventory.h"

void Inventory::Draw() {
  if (show_menu) {
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, GRAY);
    DrawText("Inventory", rect.x + 10, rect.y + 10, 18, RED);
  }
}
