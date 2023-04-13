#include "GameManager.h"

void GameManager::Update()
{
	switch (currentScene)
	{
	case GameManager::MENU:
		Menu();
		break;
	case GameManager::GAMEPLAY:
		Gameplay();
		break;
	case GameManager::HIGHSCORE:
		Highscore();
		break;
	}
}

void GameManager::Menu()
{
	int sleepTime = 16; //ms
	bool keyPressed = false;
	bool pressed1, pressed2;
	while (!keyPressed) {
		cout << "-----Main Menu-----\n  Press 1 to play\n  Press 2 to exit" << endl;
		pressed1 = GetAsyncKeyState('1') != 0;
		pressed2 = GetAsyncKeyState('2') != 0;
		keyPressed = pressed1 || pressed2;
		Sleep(sleepTime);
		system("cls");
	}
	if (pressed1) currentScene = GAMEPLAY;
	else if (pressed2) isPlaying = false;
}

void GameManager::Gameplay()
{
	//--Start
	int sleepTime = 100; //in ms
	bool gameplayRunning = true;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	vector<Wall> walls;
	vector<Brick> bricks;
	int screenWidth = 18;
	int screenHeight = 25;

	InitGameplay(screenWidth, screenHeight, &playerPad, &ball, walls, bricks);

	//--Update
	while (gameplayRunning)
	{
		//--------------- UPDATE
		ball->Update(walls, bricks, playerPad);
		playerPad->Update(screenHeight);
		CheckScore(bricks);

		//--------------- RENDER
		playerPad->Render();

		for (vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++) {
			it->Render();
		}

		for (vector<Brick>::iterator it = bricks.begin(); it != bricks.end(); it++)
		{
			it->Render();
		}

		ball->Render();


		//--------------- sleep and clear
		Sleep(sleepTime);
		system("cls");
	}

	//--End
}

void GameManager::InitGameplay(int width, int height, Pad** p, Ball** b, vector<Wall>& w, vector<Brick>& br)
{
	//PAD
	*p = new Pad(2, Vector2(height / 2, width / 2 + width / 3),'-');

	//WALLS
	w.push_back(Wall(CORNER, Vector2(0, 0), '#'));
	w.push_back(Wall(CORNER, Vector2(0, width), '#'));
	w.push_back(Wall(CORNER, Vector2(height, 0), '#'));
	w.push_back(Wall(CORNER, Vector2(height, width), '#'));
	for (int x = 1; x < width; x++) {
		w.push_back(Wall(HORIZONTAL, Vector2(0, x), '|'));
		w.push_back(Wall(HORIZONTAL, Vector2(height, x), '|'));
	}
	for (int x = 1; x < height; x++) {
		w.push_back(Wall(VERTICAL, Vector2(x, 0), '-'));
		w.push_back(Wall(VERTICAL, Vector2(x, width), '-'));
	}

	//BRICKS
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j < height; j++)
		{
			if (i != 2 && j % 2 == 0 || i == 2)
				br.push_back(Brick(1, Vector2(j, i), '-'));
			if (i == 2) j++;
		}
	}

	//BALL
	*b = new Ball(Vector2(height/2, width/2), Vector2(1, 1), 1, 'o', 3);
}

void GameManager::Highscore()
{
	cout << "Highscore" << endl;
}

void GameManager::CheckScore(vector<Brick> bricks) {
	int bricksCount;

	if (score == 0) bricksCount = bricks.size();

	if (bricksCount > bricks.size())
	{

	}
}
