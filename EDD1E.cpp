
#include <iostream>
#include <conio.h>
#include <cstdlib> //<-- for RNG?//
#include <thread> // for sleep //
#include <chrono> // for timing//
#include "GameBoard.h"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

int main() {

	int fruitX = rand() % 20;//food spawn
	int fruitY = rand() % 20;
	int x = 10, y = 10; //self spawn point//


	GameBoard gameBoard(20, 20);


	char input;


	while (true) {
		gameBoard.clear();
		//^---this gave me an issue as i removed the "{" making an infinite loop// changed from system("cls") too in class operation 

		gameBoard.setPosition(fruitX, fruitY, '*'); //food
		gameBoard.setPosition(x, y, '0'); //Snake head lol

		gameBoard.display();
	
		// check for user input //
		if (_kbhit()) {
			input = _getch(); //reads keystrokes//
			switch (input) {
			case 'w': y = max(0, y - 1); break;
			case 's': y = min(19, y + 1); break;
			case 'a': x = max(0, x - 1); break;
			case 'd': x = min(19, x + 1); break;
			case 'x': return 0;
				//classic "w,a,s,d" movment "x" to exit game//
			}
		}
		//snake eat fruit check//
		if (x == fruitX && y == fruitY) {
			fruitX = rand() % 20;//spawns new food.//
			fruitY = rand() % 20;
			gameBoard.incrementScore(); //++ score
		}

		sleep_for(milliseconds(100));
	}

		return 0;

	}
