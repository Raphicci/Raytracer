##
## Makefile for lemin in /home/zanard_a/rendu/CPE_2014_lemin/bonus
##
## Made by Adrien Vasseur
## Login   <adrien.vasseur@epitech.net>
##
## Started on  Tue Apr 14 16:47:57 2014 Adrien Vasseur
## Last update Fri Nov  6 16:56:18 2015 Antoine Lempereur
##

ifeq ($(CC), clang++)
CPPFLAGS	=	-Wno-padded
else
CC		=	g++
CPPFLAGS	=	-W -Wextra -Wall -g -std=c++11
endif

NAME		=	raytracer_putain_ma_gueule_ça_fait_plaisir

CPPFLAGS	+=	-I./include/ -I./lib/SFML-2.3/include/
CPPFLAGS	+=	-L./lib/SFML-2.3/lib/
CPPFLAGS	+=	-lsfml-network-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s
CPPFLAGS	+=	-ludev -lpthread -lX11 -lXrandr -lxcb -lGL -lX11-xcb
CPPFLAGS	+=	-lxcb-randr -lxcb-image -ljpeg
CPPFLAGS	+=	-lm -lstdc++ -DSFML_STATIC

SRC		=	src/main.cpp \
			src/Window_Config.cpp \
			src/displayer/EnvChecker.cpp \
			src/displayer/Window.cpp \
			src/network/NetworkManager.cpp \

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
