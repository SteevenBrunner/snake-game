//
// nibbler.cpp for nibbler in /home/brunne_s/rendu/cpp_nibbler
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Wed Mar 25 15:23:22 2015 Steeven Brunner
// Last update Sun Apr  5 17:31:35 2015 Steeven Brunner
//

#include <iostream>
#include <cstdlib>
#include "nibbler.hpp"

Nibbler::Nibbler()
  : mapX(6), mapY(6), winX(900), winY(900)
{
}

Nibbler::Nibbler(int gw, int gh)
{
  int	x = 0;
  int	y = 0;
  int	rd;

  exit = 0;
  pause = 0;
  speed = 100000;
  fruit = 0;
  score = 0;
  mov = 4;
  mapX = gw;
  mapY = gh;
  winX = 20 * (gw);
  winY = 20 * (gh);
  map = (int**)calloc(gh + 1, sizeof(int*));
  while (y <= gh)
    {
      x = 0;
      map[y] = (int*)calloc(gw + 1, sizeof(int));
      while (x <= gw)
	{
	  if (y == 0 || y == (gh - 1) || x == 0 || x == (gw - 1))
	    map[y][x] = 4;
	  else
	    {
	      rd = (rand() % 50);
	      if (rd < 49)
		map[y][x] = 0;
	      else
		map[y][x] = 4;
	    }
	  x++;
	}
      y++;
    }
  y = 0;
  while (y < 4)
    {
      val.first = gh/2;
      val.second = gw/2 + y;
      snake.push_back(val);
      y++;
    }
  display();
}

Nibbler::Nibbler(Nibbler const &other)
{

}

Nibbler &Nibbler::operator=(Nibbler const &other)
{

}

void Nibbler::display()
{
  int	i;

  if (map[snake[0].first][snake[0].second] == 4 || map[snake[0].first][snake[0].second] == 1)
    exit = 1;
  else if (map[snake[0].first][snake[0].second] == 3)
    {
      if (snake[snake.size() - 2].second < snake.back().second)
	{
	  val.first = snake.back().first;
	  val.second = snake.back().second + 1;
	}
      else if (snake[snake.size() - 2].second > snake.back().second)
	{
	  val.first = snake.back().first;
	  val.second = snake.back().second - 1;
	}
      else if (snake[snake.size() - 2].first < snake.back().first)
	{
	  val.first = snake.back().first + 1;
	  val.second = snake.back().second;
	}
      else if (snake[snake.size() - 2].first > snake.back().first)
	{
	  val.first = snake.back().first - 1;
	  val.second = snake.back().second;
	}
      snake.push_back(val);
      fruit = 0;
    }
  map[snake[0].first][snake[0].second] = 2;
  i = 1;
  while (i < snake.size())
    {
      map[snake[i].first][snake[i].second] = 1;
      i++;
    }
}

int Nibbler::getWinX() const
{
  return (winX);
}

int Nibbler::getWinY() const
{
  return (winY);
}

int Nibbler::getMapX() const
{
  return (mapX);
}

int Nibbler::getMapY() const
{
  return (mapY);
}

Nibbler::~Nibbler()
{

}

