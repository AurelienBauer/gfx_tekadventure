##
## Makefile for rush_incendie in /home/antoine/EPITECH/rushs/gfx_incendie
##
## Made by Antoine
## Login   <antoine@epitech.net>
##
## Started on  Fri Dec 11 20:14:15 2015 Antoine
## Last update Sun Apr 17 15:22:56 2016 
##

CC		= gcc -o

RM		= rm -f

NAME		= game

CFLAGS		+= -I/home/$(USER)/.froot/include -I./include/ -W -Wall -Wextra

LDFLAGS		+= -llapin -L/home/$(USER)/.froot/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -lm

SRCS		= sources/main.c \
		  sources/my_blit.c \
		  sources/tekpixel_alpha.c \
		  sources/stretch.c \
		  sources/clean_graph.c \
		  sources/display.c \
		  sources/finish_graph.c \
		  sources/function_graph_to_call.c \
		  sources/get_graph.c \
		  sources/graph.c \
		  sources/info.c \
		  sources/ini.c \
		  sources/profuce_graph.c \
		  sources/scope.c \
		  sources/str.c \
		  sources/render.c \
		  sources/tekchar.c \
		  sources/mouse.c \
		  sources/player.c \
		  sources/free_e.c \
		  sources/render_next.c \
		  sources/square.c \
		  sources/inventory.c \
	    sources/addnew_elem_inlist.c \
		  sources/line.c \
		  sources/blit_pix.c \
		  sources/empty_square.c \
		  sources/invent_mouve_item.c \
		  sources/square_alpha.c \
		  sources/tektext.c \
		  sources/dialog_box.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)
	cd maps && $(MAKE)

$(NAME): $(OBJS)
	$(CC) $(NAME) $(OBJS) $(LDFLAGS)
	cd maps && $(MAKE) maps_generator

clean:
	$(RM) $(OBJS)
	cd maps && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd maps && $(MAKE) fclean

re: fclean all
	cd maps && $(MAKE) re
