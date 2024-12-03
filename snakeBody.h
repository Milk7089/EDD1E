#ifndef SNAKEBODY
#define SNAKEBODY

#include <vector>
#include <utility>

class SnakeBody {

private:
	std::vector<std::pair<int, int>> body; // holds the body as (x,y) pairs

public:
	SnakeBody(int startX, int startY) {// construsctor initializing head start point
		body.push_back({ startX, startY }); // initializes w the head position
	}

	void grow() {  //grows tail longer 
		body.push_back(body.back());
	}

	//move the snake by updating positions
	void move(int dx, int dy) {


		//moves new segment of the one in front
		for (size_t i = body.size() - 1; i > 0; --i) {
			body[i] = body[i - 1];
		}

		//update head position
		body[0].first += dx;
		body[0].second += dy;
	}

	const std::vector<std::pair<int, int>>& getBody() const {
		return body; // correctly returns snakes head
	}

	std::pair<int, int> getHead() const { //gets head position 
		return body[0];
	}
};
#endif