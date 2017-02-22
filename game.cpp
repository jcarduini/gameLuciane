#include <iostream>
#include <stdlib.h>

bool gameOver;
const int width = 20;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup()
{
	gameOver = false;
	dir = STOP;
	snakeX = width/2;
	snakeY = height/2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}


void draw()
{
 	system("clear");
	int i, j;

	for (i = 0; i < width+2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width+2; j++)
		{
			if (j == 0 || j == width +1)
			{
				std::cout << "#";
			}
			else
			{		
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	for (i = 0; i < width+2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	
}

void input()
{
}

void logic()
{

}




int main(){

	setup();
	while(!gameOver)
	{
		draw();
		input();
		logic();
	}

	return 0;

}
