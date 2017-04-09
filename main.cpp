//
// main.cpp for main in /home/brunne_s/rendu/cpp_nibbler/OpenGL
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Thu Apr  2 10:20:20 2015 Steeven Brunner
// Last update Sun Apr  5 17:36:03 2015 Steeven Brunner
//

#include <unistd.h>
#include <iostream>
#include <dlfcn.h>
#include "IWindow.hpp"
#include "nibbler.hpp"

void    moove_head(Nibbler & nib)
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

void    pop_fruit(Nibbler & nib)
{
  int   x;
  int   y;

  x = rand() % (nib.mapX - 1);
  y = rand() % (nib.mapY - 1);
  while (nib.map[y][x] != 0)
    {
      x = rand() % (nib.mapX - 1);
      y = rand() % (nib.mapY - 1);
    }
  nib.map[y][x] = 3;
  nib.fruit = 1;
  nib.score += 1;
}

int	main(int ac, char **av)
{
  if (ac < 4)
    {
      std::cout << "./nibbler 10>X<95 10>Y<55 [LIBRARY]" << std::endl;
      return (1);
    }
  int	i = atoi(av[1]);
  int	j = atoi(av[2]);
  if (j > 50 || j < 10 || i < 10 || i > 95)
    {
      std::cout << "./nibbler 10>X<95 10>Y<55 [LIBRARY]" << std::endl;
      return (1);
    }
  IWindow* (*external_creator)();
  void	*dlhandle;
  Nibbler nib(i, j);
  Display disp;
  char *lib = new char[strlen(av[3]) + 3];
  strcpy(lib, "./");
  strcat(lib, av[3]);
  dlhandle = dlopen(lib, RTLD_LAZY);
  if (dlhandle == NULL)
    {
      std::cout << "can't create" << std::endl;
      return (1);
    }
  external_creator = reinterpret_cast<IWindow* (*)()>(dlsym(dlhandle, "_create"));
  if (external_creator == NULL)
    {
      std::cout << "can't external" << std::endl;
      return (1);
    }

  IWindow *window = external_creator();

  window->createWindow(nib, disp);
  while (1)
    {
      moove_head(nib);
      if (nib.fruit == 0)
	pop_fruit(nib);
      window->refreshWindow(nib, disp);
      usleep(nib.speed);
    }
  dlclose(dlhandle);
  return (0);
}
