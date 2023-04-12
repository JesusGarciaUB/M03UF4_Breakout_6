#include "Pad.h"

Pad::Pad()
{
}

void Pad::Render()
{
	for (int x = -width; x <= width; x++) {
		ConsoleXY(position.x + x, position.y);
		ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);
		std::cout << symbol;
	}
}

void Pad::Update(vector<Wall> walls)
{
	bool pressedLeft, pressedRight;
	pressedLeft = GetAsyncKeyState(VK_LEFT) != 0;
	pressedRight = GetAsyncKeyState(VK_RIGHT) != 0;

	if (pressedLeft) MoveLeft();
	else if(pressedRight) MoveRight();
}

void Pad::MoveLeft()
{
	position.x -= 1;
}

void Pad::MoveRight()
{
	position.x += 1;
}
