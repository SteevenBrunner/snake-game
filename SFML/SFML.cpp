//
// main.cpp for main in /home/brunne_s/rendu/cpp_nibbler
// 
// Made by Steeven Brunner
// Login   <brunne_s@epitech.net>
// 
// Started on  Wed Mar 25 15:27:09 2015 Steeven Brunner
// Last update Thu Apr  2 12:44:18 2015 Steeven Brunner
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../nibbler.hpp"
#include "SFML.hpp"

SFML::SFML()
{
}

SFML::~SFML()
{
}
void SFML::refreshWindow(Nibbler & nib, Display & disp)
{
  int x = 0;
  int y = 0;
  int i = 0;

  if (nib.exit == 1)
    exit(0);
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(SQ_SIZE, SQ_SIZE));
      disp.win.clear(sf::Color::Black);
      x = 0;
      while (x <= nib.mapX)
	{
	  y = 0;
	  while (y <= nib.mapY)
	    {
	      if (nib.map[y][x] == 0)
		rectangle.setFillColor(sf::Color(255, 255, 255));
	      else if (nib.map[y][x] == 1)
		rectangle.setFillColor(sf::Color(4, 99, 128));
	      else if (nib.map[y][x] == 2)
		rectangle.setFillColor(sf::Color(0, 47, 47));
	      else if (nib.map[y][x] == 3)
		rectangle.setFillColor(sf::Color(64, 65, 30));
	      else if (nib.map[y][x] == 4)
		rectangle.setFillColor(sf::Color(167, 163, 126));
	      rectangle.setPosition(x*SQ_SIZE, y*SQ_SIZE);
	      disp.win.draw(rectangle);
	      y++;
	    }
	  x++;
	}
      disp.win.display();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && nib.mov != 2)
	{
	  nib.mov = 4;
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
 && nib.mov != 4)
	{
	  nib.mov = 2;
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && nib.mov != 1)
	{
	  nib.mov = 3;
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
 && nib.mov != 3)
	{
	  nib.mov = 1;
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	{
	  nib.speed += 20000;
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
	  if (nib.speed > 20000)
	    nib.speed -= 20000;
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
	  exit(0);
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
	  if (nib.pause == 0)
	    nib.pause = 1;
	  else
	    nib.pause = 0;
	}
}

void SFML::createWindow(const Nibbler & nib, Display & disp)
{
  disp.win.create(sf::VideoMode(nib.winX, nib.winY), "Nibbler");
}

extern "C"
{
  IWindow *_create()
  {
    IWindow *tmp = new SFML();
    return tmp;
  }

  void _delete(IWindow *instance)
  {
    delete instance;
  }
}
