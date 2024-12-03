#include <iostream>
#include <conio.h>
#include <cstdlib> //<-- for RNG?//
#include <thread> // for sleep //
#include <chrono> // for timing//
#include "GameBoard.h"
#include "SnakeBody.h"

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

int main() {

	int fruitX = rand() % 20;//food spawn
	int fruitY = rand() % 20;
	
	SnakeBody snake(10, 10); // head spawn
	
	GameBoard gameBoard(20, 20); // board spawn
	
	char input;


	while (true) {
		gameBoard.clear();
		//^---this gave me an issue as i removed the "{" making an infinite loop// changed from system("cls") too in class operation 

		gameBoard.setPosition(fruitX, fruitY, '*'); //food
		auto head = snake.getHead();
		gameBoard.setPosition(head.first, head.second, '0'); //Snake head lol

		gameBoard.display();
	
		// check for user input //
		if (_kbhit()) {
			input = _getch(); //reads keystrokes//
			switch (input) {
			case 'w': snake.move(0, -1); break;
			case 's': snake.move(0, 1); break;
			case 'a': snake.move(-1, 0); break;
			case 'd': snake.move(1, 0); break;
			case 'x': return 0;
				//classic "w,a,s,d" movment "x" to exit game//
			}
		}
		//snake eat fruit check//
		if (head.first == fruitX && head.second == fruitY) {
			snake.grow();
			fruitX = rand() % 20;//spawns new food.//
			fruitY = rand() % 20;
			gameBoard.incrementScore(); //++ score
		}

		sleep_for(milliseconds(100));
	}

		return 0;

	}
