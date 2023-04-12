#include "Ball.h"

Ball::Ball()
{
}

void Ball::Bounce(Vector2 normal)
{
}

void Ball::Update(vector<Wall> walls, vector<Brick>& bricks, Pad* pads)
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

	Vector2 padPos = pads->GetPosition();
	int padX = padPos.x;
	int padY = padPos.y;

	if (padPos == targetPos)
	{
		direction.y *= -1;
	}
	
	for (int x = 1; x <= pads->GetWidth(); x++) {
		if (padX == targetPos.x - x && padY == targetPos.y) {
			direction.y *= -1;
			direction.x = 1;
		}

		if (padX == targetPos.x + x && padY == targetPos.y) {
			direction.y *= -1;
			direction.x = -1;
		}
	}

	//Check bricks
	int count = 0;
	int toerase;
	bool hit = false;
	for (auto it = bricks.begin(); it != bricks.end(); ++it)
	{
		if (it->GetPosition() == targetPos)
		{
			direction.y *= -1;
			hit = true;
			toerase = count;
		}
		count++;
	}
	if (hit) 
		bricks.erase(bricks.begin() + toerase);

	position = position + direction;
}

void Ball::Render()
{
	ConsoleXY(position.x, position.y);
	cout << "O";
}
