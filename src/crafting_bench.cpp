#include "raylib.h"
#include "crafting_bench.h"

void Crafting_Bench::Draw() {
	//DrawRectangle(50, 50, 50, 50, BLUE);
	DrawTexture(tex, rect.x, rect.y, WHITE);
}
