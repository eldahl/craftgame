#include "player.h"
#include "raylib.h"

void player::Draw() {
	DrawRectangle(X, Y, width, height, RED);
}
