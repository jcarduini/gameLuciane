#include <iostream>
#include <ncurses.h>

bool gameOver;

const int width = 20;
const int height = 20;

int snakeX, snakeY, fruitX, fruitY, score;

enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void telaInicial(){
	initscr(); /* inicia modo curses */
//	raw();
	keypad(stdscr, TRUE);
	noecho(); /* tecla pressionada nao aparece */
	printw("Ssssssssnake Game\n");
	refresh();

}


void setup(){
	gameOver = false;

}

void draw(){

	switch (getch()){
		case KEY_F(2):
			printw("F1\n");
			break;
		case 'a':
			std::cout <<"std::cout command\n";
			printw("a\n");
			break;
		case 'd':
			std::cout << "UP\n";
			break;
		case 'w':
			std::cout <<"std::cout command\n";
			printw("w\n");
			break;
		case 's':
			std::cout << "DOWN\n";
			break;
		}

	}

void input()
{
    while(!gameOver)
    {
        switch(getch())/* captura a tecla pressionada */
        {
            case 'a': 
                dir = LEFT;
                printw(" esquerda\n");
                refresh();
                break;
            case 'd': 
                dir = RIGHT;
                printw(" direita\n");
                refresh();
                break;
            case 's': 
                dir = DOWN;
                printw(" baixo\n");
                refresh();
                break;
            case 'w': 
                dir = UP;
                printw(" cima\n");
                refresh();
                break;
            case 'x':
                printw(" sair 'x'\n");
                refresh(); 
                gameOver = true;
                break;
		}
      }
}

int main(){
	telaInicial();
	setup();
	while(!gameOver)
	{
		draw();
		input();
	//	logic();
	}
	endwin();
	return 0;
}
