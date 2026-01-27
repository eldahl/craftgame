#pragma once

#include "animated_sprite_same_size.h"
#include "raylib.h"
#include "inventory.h"

class Player : public AnimatedSprite_SameSize {

public:
	bool doWalkingAnimation = true;

	Player(const char* player_sheet_path) : AnimatedSprite_SameSize(player_sheet_path, 64, 64, 9, 4) {
		rect.x = 150;
		rect.y = 150;
		rect.width = 32;
		rect.height = 48;
		offset.x = -16;
		offset.y = -8;
	};
	~Player() {};
	
	Inventory inventory = Inventory(240, 400);

	void Draw();

private:

};
