#include "Ball.h"

Ball::Ball()
{
}

void Ball::Bounce(Vector2 normal)
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
				direction.x *= -1;
				break;
			case VERTICAL:
				direction.y *= -1;
				break;
			case CORNER:
				direction.x *= -1;
				direction.y *= -1;
				break;
			}
		}
	}

	//Check pads
	//Falta comprobar els costats de les pales
	if (pads->GetPosition() == targetPos)
	{
		direction.y *= -1;
	}

	position = position + direction;
}

void Ball::Render()
{
	ConsoleXY(position.x, position.y);
	cout << "O";
}
