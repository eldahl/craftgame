#pragma once

#include "raylib.h"
#include <unordered_map>

class Map {

public:
  int RegisterCellType(const char *filePath);
  void setCell(int x, int y, int type);
  void Draw();

  Map() {};
  ~Map() {};

private:
  int size = 10;
  int cellSize = 96;
  std::unordered_map<int, Texture2D> cellTypes =
      std::unordered_map<int, Texture2D>();
};
