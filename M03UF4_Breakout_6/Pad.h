#pragma once
#include "Vector2.h"

class Pad {
private:
	Vector2 position;
	int width;
public:
	Pad();
	Pad(int w, Vector2 pos) { width = w; position = pos; }
	Vector2 GetPosition() { return position; }
	void Render();
	void Update();
	void MoveLeft();
	void MoveRight();
};