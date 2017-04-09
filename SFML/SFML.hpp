//
// window.hpp for window in /home/brunne_s/rendu/cpp_nibbler/SFML/SFMLLD
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Thu Apr  2 12:43:08 2015 Steeven Brunner
// Last update Thu Apr  2 12:44:24 2015 Steeven Brunner
//

#ifndef WINDOW_HPP__
# define WINDOW_HPP__

#include "../IWindow.hpp"
#include "../nibbler.hpp"

class SFML : public IWindow
{
public:
  SFML();
  ~SFML();

  virtual void createWindow(const Nibbler &nib, Display &disp);
  virtual void refreshWindow(Nibbler &nib, Display &disp);
};

#endif /* !WINDOW_HPP__ */
