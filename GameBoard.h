#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <vector>
#include <iomanip> //this formats the score

class GameBoard {

private:
	int width;
	int height;
	std::vector<std::vector<char>> board; //gives 2D grid for game, "might change"
	int score; // will track score

public:
	//constructor??
	GameBoard(int w, int h) : width(w), height(h), score(0), board(h, std::vector<char>(w, ' ')) {} // should be board w/ score//

	//clears the board
	void clear() {
		for (int i = 0; i < height; ++i) {
			std::fill(board[i].begin(), board[i].end(), ' ');
		}
	}

	//sets position
	void setPosition(int x, int y, char symbol) {
		if (x >= 0 && x < width && y >= 0 && y < height) {
			board[y][x] = symbol;
		}
	}

	//board display

	void display() const {
		//score box display//
		std::cout << "score" << std::setw(4) << score << std::endl;
		std::cout << "--------------------" << std::endl; 

		for (const auto& row : board) {
			for (const auto& cell : row) {
				std::cout << cell;
			}
			std::cout << std::endl;
		}
	}
	//increments score
	void incrementScore() {
		score++;
	}
};
#endif 
