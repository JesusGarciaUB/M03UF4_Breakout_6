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

	InitGameplay(15, 25, &playerPad, &ball, walls, bricks);

	//--Update
	while (gameplayRunning)
	{
		playerPad->Render();
		Sleep(sleepTime);
		system("cls");
	}

	//--End
}

void GameManager::InitGameplay(int width, int height, Pad** p, Ball** b, vector<Wall>& w, vector<Brick>& br)
{
	*p = new Pad(3, Vector2(width / 2, height / 2 + height / 4),'-');
	w.push_back(Wall(CORNER, Vector2(0, 0), 'W'));
	w.push_back(Wall(CORNER, Vector2(0, width), 'W'));
	w.push_back(Wall(CORNER, Vector2(height, 0), 'W'));
	w.push_back(Wall(CORNER, Vector2(height, width), 'W'));
	for (int x = 1; x < width - 1; x++) {
		w.push_back(Wall(HORIZONTAL, Vector2(0, x), 'W'));
	}
	for (int x = 1; x < height - 1; x++) {
		w.push_back(Wall(VERTICAL, Vector2(x, 0), 'W'));
		w.push_back(Wall(VERTICAL, Vector2(x, width), 'W'));
	}

	//*b = new Ball(Vector2(), Vector2(), 1, 'o');
}

void GameManager::Highscore()
{
	cout << "Highscore" << endl;
}
