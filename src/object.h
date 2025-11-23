#pragma once

#include "raylib.h"
class Object {
public:

	Object() {
		rect.x = 0;
		rect.y = 0;
		rect.width = 0;
		rect.height = 0;
	};
	~Object() {};

	Rectangle rect;
	bool isSolid = false;
	
	virtual void Draw() = 0;
private:

};
