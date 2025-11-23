#include "player.h"
#include "animated_sprite_same_size.h"

void Player::Draw() {
	AnimatedSprite_SameSize::Draw(this->doWalkingAnimation);
}
