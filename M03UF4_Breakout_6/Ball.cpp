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
	Vector2 targetPos = position + direction;

	//Check walls
	for (auto it = walls.begin(); it != walls.end(); it++)
	{
		if (it->GetPosition() == targetPos)
		{
			switch (it->GetType())
			{
			case HORIZONTAL:
				direction.y *= -1;
				break;
			case VERTICAL:
				direction.x *= -1;
				break;
			case CORNER:
				direction.x *= -1;
				direction.y *= -1;
				break;
			}
		}
	}

	position = position + direction;
}

void Ball::Render()
{
	ConsoleXY(position.x, position.y);
	cout << "O";
}
