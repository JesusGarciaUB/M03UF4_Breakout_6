#pragma once
#include <iostream>
#include <windows.h>

class GameManager {
private:
	void Menu();
	void Gameplay();
	void Highscore();
public:
	enum Scene{MENU, GAMEPLAY, HIGHSCORE};
	Scene currentScene;
	bool isPlaying;

	GameManager() : currentScene(MENU), isPlaying(true) {}
	void Update();
};