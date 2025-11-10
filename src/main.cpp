#include "raylib.h"
#include "player.h"

int main(void) {
  InitWindow(800, 600, "Craft game");
	SetTargetFPS(60);

	player p = player();

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_W)) {
			p.Y -= 1;
		}
    if (IsKeyDown(KEY_S)) {
			p.Y += 1;
		}
    if (IsKeyDown(KEY_A)) {
			p.X -= 1;
		}
    if (IsKeyDown(KEY_D)) {
			p.X += 1;
		}


		BeginDrawing();
    {
      ClearBackground(RAYWHITE);
      DrawText("Congrats! You created your first window!", 190, 200, 20,
               LIGHTGRAY);
			p.Draw();
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
