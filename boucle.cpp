//
// main.cpp for main in /home/brunne_s/rendu/cpp_nibbler
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Tue Mar 31 14:12:08 2015 Steeven Brunner
// Last update Wed Apr  1 13:57:20 2015 Steeven Brunner
//

#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
#include <unistd.h>
#include "nibbler.hpp"

void	moove_head(Nibbler & nib)
{
  if (nib.pause == 0)
    {
      if (nib.mov == 4 && nib.snake[1].second >= nib.snake[0].second)
	{
	  nib.val.first = nib.snake[0].first;
	  nib.val.second = nib.snake[0].second - 1;
	  nib.snake.insert(nib.snake.begin(), nib.val);
	  nib.map[nib.snake.back().first][nib.snake.back().second] = 0;
	  nib.snake.pop_back();
	  nib.display();
	}
      else if (nib.mov == 2 && nib.snake[1].second <= nib.snake[0].second)
	{
	  nib.val.first = nib.snake[0].first;
	  nib.val.second = nib.snake[0].second + 1;
	  nib.snake.insert(nib.snake.begin(), nib.val);
	  nib.map[nib.snake.back().first][nib.snake.back().second] = 0;
	  nib.snake.pop_back();
	  nib.display();
	}
      else if (nib.mov == 1 && nib.snake[1].first >= nib.snake[0].first)
	{
	  nib.val.first = nib.snake[0].first - 1;
	  nib.val.second = nib.snake[0].second;
	  nib.snake.insert(nib.snake.begin(), nib.val);
	  nib.map[nib.snake.back().first][nib.snake.back().second] = 0;
	  nib.snake.pop_back();
	  nib.display();
	}
      else if (nib.mov == 3 && nib.snake[1].first <= nib.snake[0].first)
	{
	  nib.val.first = nib.snake[0].first + 1;
	  nib.val.second = nib.snake[0].second;
	  nib.snake.insert(nib.snake.begin(), nib.val);
	  nib.map[nib.snake.back().first][nib.snake.back().second] = 0;
	  nib.snake.pop_back();
	  nib.display();
	}
    }
}

void	pop_fruit(Nibbler & nib)
{
  int	x;
  int	y;

  x = rand() % (nib.mapX - 1);
  y = rand() % (nib.mapY - 1);
  while (nib.map[y][x] != 0)
    {
      x = rand() % (nib.mapX + 1);
      y = rand() % (nib.mapY + 1);
    }
  nib.map[y][x] = 3;
  nib.fruit = 1;
}

int	main(int ac, char **av)
{
  int	i;
  int	j;
  Display disp;

  i = atoi(av[1]);
  j = atoi(av[2]);
  Nibbler nib(i , j);
  createWindow(nib, disp);
  while (1)
    {
      moove_head(nib);
      if (nib.fruit == 0)
	pop_fruit(nib);
      /*      if (nib.map[nib.headY][nib.headX - 1] == 4)
	return (0);
      nib.map[nib.headY][nib.headX - 1] = 2;
      nib.map[nib.headY][nib.headX] = 1;
      nib.map[nib.lastY][nib.lastX] = 0;
      nib.headX -= 1;
      nib.lastX -= 1;*/
      refreshWindow(nib, disp);
      usleep(nib.speed);
    }
  return 0;
}
