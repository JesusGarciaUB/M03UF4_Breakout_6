#pragma once
#include <vector>

#include "ConsoleControl.h"
#include "Vector2.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"

class Ball {
private:
	Vector2 position;
	Vector2 direction;
	int damage;
	char symbol;
public:
	Ball();
	Ball(Vector2 pos, Vector2 dir, int d, char c) 
		: position(pos), direction(dir), damage(d), symbol(c) {}
	void Bounce(Vector2 normal);
	void Update(Wall walls[], Brick bricks[], Pad pads[]);
	void Update(vector<Wall> walls, vector<Brick> bricks,Pad* pads);
	void Render();
	int GetDamage() { return damage; }
	Vector2 GetDirection() { return direction; }
	Vector2 GetPosition() { return position; }
	void SetDirection(Vector2 n) { direction = n; }
};