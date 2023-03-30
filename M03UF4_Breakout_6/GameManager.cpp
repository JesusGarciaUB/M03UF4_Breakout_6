#include "GameManager.h"

using namespace std;

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
	int sleepTime = 16;
	cout << "Gameplay" << endl;
	Sleep(sleepTime);
}

void GameManager::Highscore()
{
	cout << "Highscore" << endl;
}
