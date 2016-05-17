/*
** explorer.h for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps/includes
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:21:55 2016 Thomas HENON
** Last update Fri Apr 15 15:21:56 2016 thomas
*/

#ifndef __EXPLORER_H__
# define __EXPLORER_H__

#include <sys/types.h>
#include <dirent.h>

# define EXPLORER_WIDTH 500
# define EXPLORER_HEIGHT 500
# define ALPHA_HEIGHT 25

typedef struct		s_explorer
{
  char			*win_name;
  t_bunny_window	*win;
  t_bunny_pixelarray	*buffer;
  char			*extension;
  char			*current_path;
  char			*img;
  t_linkedlist		*files;
}			t_explorer;

char	explorer_on_enter(t_explorer *explorer, int *i);
t_bunny_response	explorer_on_key(t_bunny_event_state state,
					t_bunny_keysym key,
					void *data);
char	explorer_read_files(t_explorer *explorer);
char	explorer_display_files(t_explorer *explorer, int start);
char	*explorer_get_focused_file_name(t_explorer *explorer, int start);
char	explorer_on_enter_file(char *file_name, char *path,
			       t_explorer *explorer);
#endif
