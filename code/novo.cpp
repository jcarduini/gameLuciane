#include <iostream> //std::cout
#include <ncurses.h> //win
#include <cstdlib> //rand()

bool gameOver;
const int width = 20;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup(){

	gameOver = false;
	dir = STOP;
	snakeX = width / 2;
	snakeY = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw(){
	
	system("clear");
	int i;	

	for (i = 0; i < width + 1; i++){
		std::cout << "#";
	}
	std::cout << std::endl;
	int j;

	for (j = 1; j < height - 1; j++){
		for (i = 0; i < width + 2; i++){
			if (i == 0 || i == width - 1)
				std::cout<< "#";
			if (i == snakeX && j == snakeY)
				std::cout << "O";
			else 
				if (i == fruitX && j == fruitY)
					std::cout << "*";
				else
					std::cout<< " ";
		}
		std::cout << std::endl;
	}

	for (i = 0; i < width + 1; i++){
		std::cout << "#";
	}
	std::cout<<std::endl;
}

int main(){

	setup();
	while(!gameOver)
		draw();
	return 0;
}
