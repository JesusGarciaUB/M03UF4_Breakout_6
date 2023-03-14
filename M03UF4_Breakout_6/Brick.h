#pragma once
#include "Vector2.h"

class Brick {
private:
	Vector2 position;
	int health;
public:

	Brick();
	Brick(int h, Vector2 pos) { health = h; position = pos; }
	Vector2 GetPosition() { return position; }
	int GetHealth() { return health; }
	void Render();
	void TakeDamage();
};