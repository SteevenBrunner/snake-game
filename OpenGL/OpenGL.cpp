//
// main.cpp for main in /home/brunne_s/rendu/cpp_nibbler
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Wed Mar 25 15:27:09 2015 Steeven Brunner
// Last update Thu Apr  2 15:52:34 2015 Steeven Brunner
//

#include <unistd.h>
#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include "OpenGL.hpp"
#include "../IWindow.hpp"
#include "../nibbler.hpp"

OpenGL::OpenGL()
{
}

OpenGL::~OpenGL()
{
}

void	OpenGL::putSquares(int x, int y, int color)
{
  glBegin(GL_QUADS);
  if (color == 1)
    glColor3f(0, 255, 0);
  else if (color == 2)
    glColor3f(50, 255, 0);
  else if (color == 3)
    glColor3f(255, 0, 0);
  else if (color == 4)
    glColor3f(255, 0, 255);
  else
    glColor3f(0, 0, 0);    
  glVertex2f(0 + x, 0 + y);
  glVertex2f(SQ_SIZE + x, 0 + y);
  glVertex2f(SQ_SIZE + x, SQ_SIZE + y);
  glVertex2f(0 + x, SQ_SIZE + y);
  glEnd();
}

void OpenGL::refreshWindow(Nibbler &nib, Display &disp)
{
  bool continuer = true;
  int	color;
  int	i = 0;
  int	j = 0;

  if (nib.exit == 1)
    exit(0);
  while (SDL_PollEvent(&disp.event) != 0)
    {
      if (disp.event.type == SDL_QUIT)
	exit(0);
      else if (disp.event.type == SDL_KEYDOWN)
	{
	  switch(disp.event.key.keysym.sym)
	    {
	    case SDLK_LEFT:
	      if (nib.mov != 2)
		nib.mov = 4;
	      break;
	    case SDLK_RIGHT:
	      if (nib.mov != 4)
		nib.mov = 2;
	      break;
	    case SDLK_UP:
	      if (nib.mov != 3)
		nib.mov = 1;
	      break;
	    case SDLK_DOWN:
	      if (nib.mov != 1)
		nib.mov = 3;
	      break;
	    case SDLK_KP_MINUS:
	      nib.speed += 20000;
	      break;
	    case SDLK_KP_PLUS:
	      if (nib.speed > 20000)
		nib.speed -= 20000;
	      break;
	    case SDLK_SPACE:
	      if (nib.pause == 0)
		nib.pause = 1;
	      else
		nib.pause = 0;
	      break;
	    case SDLK_ESCAPE:
	      exit(0);
	      break;
	    default:
	      break;	 
	    }
	}
    }
  glClear(GL_COLOR_BUFFER_BIT);
  while (i <= nib.mapY)
    {
      while (j <= nib.mapX)
	{
	  putSquares(j * SQ_SIZE, i * SQ_SIZE, nib.map[i][j]);
	  j++;
	}
      j = 0;
      i++;
    }
  glFlush();
  SDL_GL_SwapBuffers();
}

void	OpenGL::createWindow(const Nibbler &nib, Display &disp)
{
  bool continuer = true;
  int	color;
  int	i = 0;
  int	j = 0;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      std::cerr << "Could not initialise SDL: " << SDL_GetError() << std::endl;
      exit(1);
    }
  if (!SDL_SetVideoMode(nib.winX, nib.winY, 32, SDL_OPENGL))
    {
      std::cerr << "Could not set video mode: " << SDL_GetError() << std::endl;
      SDL_Quit();
      exit(1);
    }
  SDL_WM_SetCaption("Nibbler de folie maggle", NULL);
  glOrtho(0, nib.winX, nib.winY, 0, -1, 1);
  SDL_WaitEvent(&disp.event);
  if (disp.event.type == SDL_QUIT)
    SDL_Quit();
  glClear(GL_COLOR_BUFFER_BIT);
  while (i <= nib.mapY)
    {
      while (j <= nib.mapX)
	{
	  putSquares(j * SQ_SIZE, i * SQ_SIZE, nib.map[i][j]);
	  j++;
	}
      j = 0;
      i++;
    }
  glFlush();
  SDL_GL_SwapBuffers();
}

extern "C"
{
  IWindow *_create()
  {
    IWindow *tmp = new OpenGL();
    return tmp;
  }

  void _delete(IWindow *instance)
  {
    delete instance;
  }
}
