#pragma once

#include "object.h"
#include "raylib.h"
#include <vector>

///
/// SameSize refers to the spritesheet being equal length on both dimensions.
///
class AnimatedSprite_SameSize : public Object {
public:
  Vector2 offset = Vector2();

	int spriteWidth = 0;
  int spriteHeight = 0;
  int spritesHorizontal = 0;
  int spritesVertical = 0;

  std::vector<std::vector<Rectangle>> spriteRects =
      std::vector<std::vector<Rectangle>>();

  Texture2D texture;

  float frame_duration = 0.08;

  double timeAccumulator = 0;
  int currentVerticalLine = 0;
  int currentHorizontalLine = 0;

  AnimatedSprite_SameSize(const char *imagePath, int _spriteW, int _spriteH,
                          int _countH, int _countV) {
    // Dimensions.
    spriteWidth = _spriteW;
    spriteHeight = _spriteH;
    spritesHorizontal = _countH;
    spritesVertical = _countV;

    // Load spritesheet.
    Image img = LoadImage(imagePath);
    texture = LoadTextureFromImage(img);

    // Calculate the rectangles of the images within the spritesheet.
    calculateSpriteRects();
  };
  ~AnimatedSprite_SameSize() {};

	void SetOffset(Vector2 _offset) {
		offset = _offset;
	}

  void SetHorizontalLine(int _horizontalLine) {
    currentHorizontalLine = _horizontalLine;
  }
  void SetVerticalLine(int _verticalLine) {
    currentVerticalLine = _verticalLine;
  }

  void SetFrameDuration(float _frame_duration) {
    frame_duration = _frame_duration;
  };

  void Draw(bool doWalking) {
    timeAccumulator += GetFrameTime();
    if (doWalking && timeAccumulator >= frame_duration) {
      timeAccumulator = 0;
      if (currentHorizontalLine == spritesHorizontal - 1)
        currentHorizontalLine = 0;
      else
        currentHorizontalLine++;
    }

    Vector2 pos = Vector2();
    pos.x = rect.x + offset.x;
    pos.y = rect.y + offset.y;
    DrawTextureRec(
        texture, spriteRects.at(currentVerticalLine).at(currentHorizontalLine),
        pos, WHITE);
  };

private:
  void calculateSpriteRects() {
    // Clear vector when not empty.
    if (!spriteRects.empty()) {
      spriteRects.clear();
    }

    // Calculate the rectangles.
    Rectangle r = Rectangle();
    r.width = spriteWidth;
    r.height = spriteHeight;

    for (int y = 0; y < spritesVertical; y++) {
      auto rectLine = std::vector<Rectangle>();
      for (int x = 0; x < spritesHorizontal; x++) {
        r.x = x * spriteWidth;
        r.y = y * spriteHeight;
        // How to interface with vector of vector
        rectLine.push_back(Rectangle(r));
      }
      spriteRects.push_back(rectLine);
    }
  };
};
