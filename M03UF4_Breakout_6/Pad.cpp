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

void Pad::Update(Wall walls[])
{
}

void Pad::MoveLeft()
{
}

void Pad::MoveRight()
{
}
