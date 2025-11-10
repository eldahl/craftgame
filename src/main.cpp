#include "raylib.h"
#include "player.h"
#include "map.h"

int main(void) {
  InitWindow(800, 600, "Craft game");
	SetTargetFPS(60);

	Map m = Map();
	player p = player();

	m.RegisterCellType("./assets/grass.png");

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_W)) {
			p.Y -= 2;
		}
    if (IsKeyDown(KEY_S)) {
			p.Y += 2;
		}
    if (IsKeyDown(KEY_A)) {
			p.X -= 2;
		}
    if (IsKeyDown(KEY_D)) {
			p.X += 2;
		}


		BeginDrawing();
    {
      ClearBackground(RAYWHITE);
      m.Draw();
			DrawText("Congrats! You created your first window!", 190, 200, 20,
               LIGHTGRAY);

			p.Draw();
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
