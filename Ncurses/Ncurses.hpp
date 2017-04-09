//
// Ncurses.hpp for Ncurses in /home/brunne_s/rendu/cpp_nibbler/Ncurses
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Thu Apr  2 15:32:34 2015 Steeven Brunner
// Last update Thu Apr  2 15:46:13 2015 Steeven Brunner
//

#include "../nibbler.hpp"
#include "../IWindow.hpp"

class Ncurses : public IWindow
{
public:
  Ncurses();
  ~Ncurses();

  virtual void createWindow(const Nibbler &nib, Display &disp);
  virtual void refreshWindow(Nibbler &nib, Display &disp);
  void	printRectangle(int x, int y, int height, int width, int color_mod);
};
