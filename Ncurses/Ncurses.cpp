//
// final.cpp for final.cpp in /home/brunne_s/rendu/cpp_nibbler/GTK
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Wed Mar 25 15:19:16 2015 Steeven Brunner
// Last update Sun Apr  5 17:36:47 2015 Steeven Brunner
//

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Ncurses.hpp"
#include "../nibbler.hpp"

Ncurses::Ncurses()
{
}

Ncurses::~Ncurses()
{
}

void Ncurses::printRectangle(int x, int y, int height, int width, int color_mod)
{
  int i = x;
  int j;

  attrset(COLOR_PAIR(color_mod));
  while (i < x + height)
    {
      j = y;
      while (j <= y + width)
	{
	  move(i,j);
	  printw("-");
	  j++;
	}
      i++;
    }
}

void	Ncurses::createWindow(const Nibbler &nib, Display &disp)
{
  (void)nib;
  (void)disp;
}

void	Ncurses::refreshWindow(Nibbler &nib, Display &disp)
{
  int	i = 0;
  int	j = 0; 

  //initialisation
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

  //

  curs_set(0);
  start_color();

  init_pair(1, COLOR_CYAN, COLOR_CYAN);     //corps en vert
  init_pair(2, COLOR_BLUE, COLOR_BLUE);     //tete en rouge
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW); //nourriture en jaune
  init_pair(4, COLOR_RED, COLOR_RED);       //murs en magenta
  init_pair(5, COLOR_WHITE, COLOR_WHITE);   //fond en blanc

  while (i < nib.mapY)
    {
      while (j < nib.mapX)
	{
	  if (nib.map[i][j] == 0)
	    printRectangle(i * 1, j * 2, 1, 1, 5);
	  else if (nib.map[i][j] == 1)
	    printRectangle(i * 1, j * 2, 1, 1, 1);
	  else if (nib.map[i][j] == 2)
	    printRectangle(i * 1, j * 2, 1, 1, 2);
	  else if (nib.map[i][j] == 3)
	    printRectangle(i * 1, j * 2, 1, 1, 3);
	  else if (nib.map[i][j] == 4)
	    printRectangle(i * 1, j * 2, 1, 1, 4);
	  refresh();
	  j++;
	}
      j = 0;
      i++;
    }  
  refresh();
  
  int	key = getch();

  if (key == KEY_LEFT && nib.mov != 2)
    nib.mov = 4;
  else if (key == KEY_RIGHT && nib.mov != 4)
    nib.mov = 2;
  else if (key == KEY_UP && nib.mov != 3)
    nib.mov = 1;
  else if (key == KEY_DOWN && nib.mov != 1)
    nib.mov = 3;
  else if (key == 43)
    nib.speed -= 20000; //quick speed
  else if (key == 45)
    nib.speed += 20000; //slow speed
  else if (key == 27 || nib.exit == 1)
    {
      endwin(); //escape
      std::cout << "Score obtenu " << nib.score - 1 << std::endl;
      exit(1);
    }
  else if (key == ' ' && nib.pause == 1)
    nib.pause = 0;
  else if (key == ' ' && nib.pause == 0)
    nib.pause = 1;
}

extern "C"
{
  IWindow *_create()
  {
    IWindow *tmp = new Ncurses();
    return tmp;
  }

  void _delete(IWindow *instance)
  {
    delete instance;
  }
}
