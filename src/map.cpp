#include <cstdio>
#include "map.h"
#include "raylib.h"

void Map::Draw() {
  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) {
      DrawTexture(cellTypes[1], x * cellSize, y * cellSize, WHITE);
      Rectangle r = Rectangle();
      r.x = x * cellSize;
      r.y = y * cellSize;
      r.width = cellSize;
      r.height = cellSize;
      //DrawRectangleLinesEx(r, 0.5, BLACK);
    }
  }
}

void Map::setCell(int x, int y, int type) {}

int Map::RegisterCellType(const char* filePath) {
	Texture2D tex = LoadTexture(filePath);
	int typeCount = cellTypes.size() + 1;
	cellTypes[typeCount] = tex;
	printf("Added new cell type with texture %s to map.\n", filePath);
	return typeCount;
}
