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
	int sleepTime = 16; //in ms
	bool gameplayRunning = true;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	vector<Wall> walls;
	vector<Brick> bricks;

	InitGameplay(15, 25, playerPad, ball, walls, bricks);

	//--Update
	while (gameplayRunning)
	{
		playerPad->Render();


		cout << "Gameplay" << endl;
		Sleep(sleepTime);
		system("cls");
	}

	//--End
}

void GameManager::InitGameplay(int width, int height, Pad* p, Ball* b, vector<Wall>& w, vector<Brick>& br)
{
	p = new Pad(3, Vector2(width / 2, height / 2 + height / 4),'-');
}

void GameManager::Highscore()
{
	cout << "Highscore" << endl;
}
