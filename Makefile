##
## Makefile for Makefile in /home/brunne_s/rendu/cpp_nibbler
## 
## Made by Steeven Brunner
## Login   <brunne_s@epitech.net>
## 
## Started on  Tue Mar 31 14:13:17 2015 Steeven Brunner
## Last update Sun Apr  5 17:24:20 2015 Steeven Brunner
##

NAME	=	nibbler
SRC	=	main.cpp \
		nibbler.cpp
OBJ	=	$(SRC:.cpp=.o)

#LIB_OPENGL =	lib_opengl.so
#OPENGL_SRC =	OpenGL/OpenGL.cpp
#OPENGL_OBJ =	$(OPENGL_SRC:.cpp=.o)
#OPENGL_LDFLAGS = -lGL -lSDL -lGLU

#LIB_SFML =	lib_sfml.so
#SFML_SRC =	SFML/SFML.cpp
#SFML_OBJ =	$(SFML_SRC:.cpp=.o)
#SFML_LDFLAGS =	-lsfml-graphics -lsfml-window

LIB_NCURSES =	lib_ncurses.so
NCURSES_SRC =	Ncurses/Ncurses.cpp
NCURSES_OBJ =	$(NCURSES_SRC:.cpp=.o)
NCURSES_LDFLAGS = -lncurses

CXXFLAGS +=     -std=gnu++11 -fPIC
LDFLAGS	+=	-ldl -lsfml-graphics

all:	$(LIB_OPENGL) $(LIB_SFML) $(LIB_NCURSES) $(NAME)

$(NAME): $(SFML_OBJ) $(OPENGL_OBJ) $(OBJ) 
	g++ -o $(NAME) $(OBJ) $(LDFLAGS)

#$(LIB_OPENGL): $(OPENGL_OBJ)
#	g++ -shared -o $(LIB_OPENGL) $(OPENGL_OBJ) $(OPENGL_LDFLAGS)

#$(LIB_SFML): $(SFML_OBJ)
#	g++ -shared -o $(LIB_SFML) $(SFML_OBJ) $(SFML_LDFLAGS)

$(LIB_NCURSES): $(NCURSES_OBJ)
	g++ -shared -o $(LIB_NCURSES) $(NCURSES_OBJ) $(NCURSES_LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(SFML_OBJ)
	rm -f $(OPENGL_OBJ)
	rm -f $(NCURSES_OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB_SFML)
	rm -f $(LIB_OPENGL)
	rm -f $(LIB_NCURSES)

re:	fclean all
