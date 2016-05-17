##
## Makefile for  in /home/thomas/Documents/epitech/gfx_tekadventure/maps
##
## Made by Thomas HENON
## Login   <thomas.henon@epitech.net>
##
## Started on  Fri Apr 15 15:24:50 2016 Thomas HENON
## Last update Sun Apr 17 14:33:58 2016 John Doe
##

CC		= gcc

RM		= rm -f

NAME		= maps_generator

CFLAGS		+= -I/home/$(USER)/.froot/include -I./ -I ./includes
CFLAGS    += -l my -L ./my -I ./my

LDFLAGS		+= -llapin -L/home/$(USER)/.froot/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -lm
LDFLAGS   += -l my -L ./my -I ./my

SRCS		= main.c \
					bases.c \
					scaling.c \
					tektext.c \
					tektext2.c \
					button.c \
					linkedlists.c \
					toolbar_buttons_events.c \
					toolbar_buttons_events2.c \
					util.c \
					path.c \
					maps.c \
					toolbar_buttons.c \
					toolbar_events.c \
					wins_events.c \
					circle.c \
					ini_serializer.c \
					maps_events.c \
					maps_point.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		  $(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
			mv $(NAME) ../

clean:
		  $(RM) $(OBJS)

fclean: clean
		  $(RM) ../$(NAME)

re: fclean all
