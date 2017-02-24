#include <iostream>
#include <ncurses.h>

bool gameOver;


void setup(){
	gameOver = false;
	initscr(); /* inicia modo curses */
	printw("Ssssssssnake Game\n");
	refresh();
}

void draw(){

//	WINDOW * win;
//	win = newwin(20,20,0,0);
	switch (getch()){
		case 'a':
			std::cout <<"std::cout command\n";
			printw("a\n");
			break;
		case 'd':
			std::cout << "UP\n";
			break;
		}
}

int main(){
	setup();
	while(!gameOver)
	{
		draw();
	//	input();
	//	logic();
	}
	endwin();
	return 0;
}
