
#include <iostream>
#include <conio.h>
#include <cstdlib> //<-- for RNG?//
#include <thread> // for sleep //
#include <chrono> // for timing//

using namespace std;

int main() {

	int fruitX = rand() % 20;//food spawn
	int fruitY = rand() % 20;
	int x = 10, y = 10; //self spawn point//
	char input;

	while (true) {
		system("cls"); //<---this gave me an issue as i removed the "{" making an infinite loop//

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (i == fruitY && j == fruitX) {
					cout << "*"; //fruits//
				}
				else if (i == y && j == x) {
					cout << "0"; //snake head//
				}
				else {
					cout << " "; //dead space//
				}
			}
			cout << endl;
	}

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
	}


	this_thread::sleep_for(chrono::milliseconds(100));
}

return 0;

}
