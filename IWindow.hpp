//
// IWindow.hpp for IWindow in /home/brunne_s/rendu/cpp_nibbler/OpenGL
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Thu Apr  2 10:11:55 2015 Steeven Brunner
// Last update Thu Apr  2 14:37:53 2015 Steeven Brunner
//

#ifndef IWINDOW_HPP__
# define IWINDOW_HPP__

#include "nibbler.hpp"

class IWindow
{
public:
  virtual ~IWindow() {};
  virtual void	createWindow(const Nibbler &nib, Display &disp) = 0;
  virtual void	refreshWindow(Nibbler &nib, Display &disp) = 0;
};

#endif /* !IWINDOW_HPP__ */
