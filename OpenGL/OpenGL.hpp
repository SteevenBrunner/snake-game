//
// window.hpp for window in /home/brunne_s/rendu/cpp_nibbler/OpenGL
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Thu Apr  2 10:29:48 2015 Steeven Brunner
// Last update Thu Apr  2 14:38:27 2015 Steeven Brunner
//

#ifndef WINDOW_HPP__
# define WINDOW_HPP__

#include <SDL/SDL.h>
#include "../IWindow.hpp"
#include "../nibbler.hpp"

class OpenGL : public IWindow
{
public:
  OpenGL();
  ~OpenGL();

  virtual void createWindow(const Nibbler &nib, Display &disp);
  virtual void refreshWindow(Nibbler &nib, Display &disp);
  void	putSquares(int x, int y, int color);
};

#endif /* !WINDOW_HPP__ */
