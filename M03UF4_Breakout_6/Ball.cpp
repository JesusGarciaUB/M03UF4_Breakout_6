#include "Ball.h"

Ball::Ball()
{
}

void Ball::Bounce(Vector2 normal)
{
}

void Ball::Update(Wall walls[], Brick bricks[], Pad pads[])
{
}

void Ball::Update(vector<Wall> walls, vector<Brick> bricks, Pad* pads)
{
}

void Ball::Render()
{
	ConsoleXY(position.x, position.y);
	cout << "O";
}
