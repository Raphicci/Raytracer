##
## Makefile for lemin in /home/zanard_a/rendu/CPE_2014_lemin/bonus
##
## Made by Adrien Vasseur
## Login   <adrien.vasseur@epitech.net>
##
## Started on  Tue Apr 14 16:47:57 2014 Adrien Vasseur
## Last update Fri Nov 20 17:02:57 2015 Antoine Lempereur
##

ifeq ($(CC), clang++)
CPPFLAGS	=	-Wno-padded
else
CC		=	g++
CPPFLAGS	=	-W -Wextra -Wall -g -std=c++11
endif

NAME		=	raytracer

CPPFLAGS	+=	-I./include/
CPPFLAGS	+=	-lsfml-network -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS	+=	-lX11

MAIN		=	src/main.cpp

MAINTEST	=	test/main.cpp

SRC		=	src/tools/Log.cpp \
			src/tools/Vector.cpp \
			src/tools/Color.cpp \
			src/Window_Config.cpp \
			src/displayer/EnvChecker.cpp \
			src/displayer/Window.cpp \
			src/displayer/Frame.cpp \
			src/parser/SceneParser.cpp \
			src/engine/Sphere.cpp \
			src/engine/Object.cpp \
			src/engine/Scene.cpp \
			src/engine/Light.cpp \
			src/engine/Ray.cpp \
			src/engine/Box.cpp \

OBJ		=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

OBJTEST		=	$(SRC:.cpp=.o) $(MAINTEST:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(OBJ) $(INC) -o $(NAME) $(CPPFLAGS)

test:			$(OBJTEST)
			$(CC) $(OBJTEST) $(INC) -o test/test $(CPPFLAGS)

clean:
			rm -f $(OBJ)
			rm -f $(OBJTEST)

fclean:			clean
			rm -f $(NAME)
			rm -f test/test

re:			fclean all

.PHONY:			all clean fclean
