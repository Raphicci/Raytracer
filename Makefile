##
## Makefile for lemin in /home/zanard_a/rendu/CPE_2014_lemin/bonus
##
## Made by Adrien Vasseur
## Login   <adrien.vasseur@epitech.net>
##
## Started on  Tue Apr 14 16:47:57 2014 Adrien Vasseur
## Last update Fri Nov  6 17:23:03 2015 Adrien Vasseur
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

SRC		=	src/main.cpp \
			src/Window_Config.cpp \
			src/displayer/EnvChecker.cpp \
			src/displayer/Window.cpp

OBJS		=	$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) $(INC) -o $(NAME) $(CPPFLAGS)

clean:
			rm -f $(OBJS)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean
