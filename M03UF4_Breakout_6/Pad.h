#pragma once
#include "Vector2.h"
#include "Wall.h"

class Pad {
private:
	Vector2 position;
	int width;
	char symbol;
public:
	Pad();
	Pad(int w, Vector2 pos, char c) { width = w; position = pos; symbol = c; }
	Vector2 GetPosition() { return position; }
	void Render();
	void Update(Wall walls[]);
	void MoveLeft();
	void MoveRight();
};