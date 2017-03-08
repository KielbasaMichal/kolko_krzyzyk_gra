#pragma once
#include "SFML/Graphics.hpp"
#include "textbox.h"
#include "button.h"
#include "pole.h"
#include <iostream>
#include <string>

#define WIDTH 800
#define HEIGHT 500

enum State { START, PLAY, FINISH, END };

void start();
void play();
void finish();
void error(std::string co);

struct score
{
	std::string title = "Wygrywa";
	std::wstring *winner;
	bool isTitle = true;
	int point1 = 0;
	int point2 = 0;
};