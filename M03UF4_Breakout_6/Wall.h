#pragma once
#include "Vector2.h"

enum WallType {HORIZONTAL, VERTICAL, CORNER};

class Wall {
private:
	Vector2 position;
	WallType type;
	char symbol;
public:
	Wall();
	Wall(WallType t, Vector2 pos) { type = t; position = pos; }
	Vector2 GetPosition() { return position; }
	WallType GetType() { return type; }
	void Render();
};