#include "crafting_bench.h"
#include "gui_objects_drawer.h"
#include "inventory.h"
#include "map.h"
#include "player.h"
#include "raylib.h"

bool RectangleAABB(Rectangle a, Rectangle b) {
  return (a.x < b.x + b.width && a.x + a.width > b.x && a.y < b.y + b.height &&
          a.y + a.height > b.y);
}

int main(void) {
  InitWindow(800, 600, "Craft game");
  SetTargetFPS(60);

  Map m = Map();
  Player p = Player("./assets/ph-player.png");

  GUI_Objects_Drawer gui_context = GUI_Objects_Drawer();

  Crafting_Bench c = Crafting_Bench();
  c.rect.x = 50;
  c.rect.y = 50;

  gui_context.RegisterDrawGUIObject(&c.menu);
	gui_context.RegisterDrawGUIObject(&p.inventory);

  m.RegisterCellType("./assets/grass.png");

  while (!WindowShouldClose()) {
    p.doWalkingAnimation = false;
    Rectangle newRect = Rectangle(p.rect);
    if (IsKeyDown(KEY_W)) {
      newRect.y -= 2;
      if (!RectangleAABB(newRect, c.rect)) {
        p.currentVerticalLine = 0;
        p.rect.y -= 2;
        p.doWalkingAnimation = true;
      }
    }
    if (IsKeyDown(KEY_S)) {
      newRect.y += 2;
      if (!RectangleAABB(newRect, c.rect)) {
        p.currentVerticalLine = 2;
        p.rect.y += 2;
        p.doWalkingAnimation = true;
      }
    }
    if (IsKeyDown(KEY_A)) {
      newRect.x -= 2;
      if (!RectangleAABB(newRect, c.rect)) {
        p.currentVerticalLine = 1;
        p.rect.x -= 2;
        p.doWalkingAnimation = true;
      }
    }
    if (IsKeyDown(KEY_D)) {
      newRect.x += 2;
      if (!RectangleAABB(newRect, c.rect)) {
        p.currentVerticalLine = 3;
        p.rect.x += 2;
        p.doWalkingAnimation = true;
      }
    }
    if (IsKeyPressed(KEY_I)) {
      if (p.inventory.show_menu) {
        p.inventory.HideMenu();
      } else {
        p.inventory.ShowMenu();
      }
    }
    if (IsKeyPressed(KEY_E)) {
      if (c.menu.show_menu) {
        c.menu.HideMenu();
      } else {
        c.menu.ShowMenu();
      }
    }

    BeginDrawing();
    {
      ClearBackground(RAYWHITE);
      m.Draw();

      c.Draw();

      p.Draw();

      gui_context.Draw();

      DrawText("Congrats! You created your first window!", 190, 200, 20,
               LIGHTGRAY);
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
