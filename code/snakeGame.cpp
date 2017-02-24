#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

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
	int i, j;
	for (i = 0; i < width + 3;i++)
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
			if (i == snakeY && j == snakeX)
			{
				std::cout << "o";
			}		
			else
			{	
				if (i == fruitY && j == fruitX)
				{
					std::cout << "*";
				}
				else	
				{
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}

	for (i = 0; i < width+3; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	
}

void input()
{
	initscr();
	while(true)	
	{
		/* captura a tecla pressionada */
		switch(getch())
		{
			case 'a':
				dir = LEFT;
				printw("a\n");
				refresh();
				break;
			case 'd':
				dir = RIGHT;
				printw("d\n");
				refresh();
				break;
			case 's':
				dir = DOWN;
				printw(" Reconheceu 's'\n");
				refresh();
				break;
			case 'w':
				dir = UP;
				printw(" Reconheceu 'w'\n");
				refresh();
				break;
			case 'x':
				printw(" Reconheceu 'x'\n");
				refresh();
				gameOver = true;
				break;
		}
	refresh();
//	endwin();
//	delay_output(2000);
		
	}
}

void logic()
{
	switch(dir)
	{
		case LEFT:
			snakeX--;
			break;
		case RIGHT:
			snakeX++;
			break;
		case UP:
			snakeY++;
			break;
		case DOWN:
			snakeY--;
			break; 
		default:
			break;
	}
}

int main(){

	setup();
	while(!gameOver)
	{
//		draw();
		initscr();
		printw("Sssssssssnake Game\n");
		refresh();
		input();
		logic();
	}
	endwin();
	return 0;
}
