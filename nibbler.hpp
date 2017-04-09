//
// nibbler.hpp for nibbler.hpp in /home/brunne_s/rendu/cpp_nibbler
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Wed Mar 25 17:08:46 2015 Steeven Brunner
// Last update Sun Apr  5 17:31:03 2015 Steeven Brunner
//

#ifndef NIBBLER_HPP_
# define NIBBLER_HPP_

# define SQ_SIZE 20

# include <SFML/Window.hpp>
# include <SFML/Graphics/RenderWindow.hpp>
# include <SFML/Graphics.hpp>
# include <SDL/SDL.h>
# include <vector>

class Display
{
public:
  sf::RenderWindow	win;
  SDL_Event		event;
};

class Nibbler
{
public:
  Nibbler();
  Nibbler(int, int);
  Nibbler(Nibbler const &other);
  void	display();
  int	getWinX() const;
  int	getWinY() const;
  int	getMapX() const;
  int	getMapY() const;
  Nibbler &operator=(Nibbler const &other);
  ~Nibbler();

  /*int map2[6][6] =
    {
      {4, 4, 4, 4, 4, 4},
      {4, 0, 0, 2, 0, 4},
      {4, 0, 0, 1, 0, 4},
      {4, 0, 0, 1, 0, 4},
      {4, 0, 3, 0, 0, 4},
      {4, 4, 4, 4, 4, 4}
      };*/
  int **map;

  //private:
  int mapX;
  int mapY;
  int winX;
  int winY;
  int fruit;
  int speed;
  int pause;
  std::pair<int, int> val;
  std::vector<std::pair<int, int> > snake;
  int exit;
  int mov;
  int sqsize;
  int score;
  //  void createWindow(const Nibbler nib, Display &disp);
  //  void refreshWindow(const Nibbler nib, Display &disp);
};

void	createWindow(const Nibbler & nib, Display &disp);
void	refreshWindow(Nibbler & nib, Display &disp);

#endif /* !NIBBLER_HPP__ */
