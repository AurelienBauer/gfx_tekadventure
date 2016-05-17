/*
** position.h for tekadventure in /home/carlen/gfx_tekadventure/position
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Tue Apr  5 20:38:55 2016 carlen
** Last update Thu Apr 14 16:14:46 2016 carlen
*/

#ifndef POSITION_H_
# define POSITION_H_
# define NB_ELEM_INI 6
# define INT 0
# define PRT_CHAR 1
# define DEFAULT_NO_VALUE -42
# define DEFAULT_INT_TAB_LEN 255
# define DEFAULT_CHAR_TAB_LEN 513
# define END_STR '\0'

typedef struct		s_position
{
  int			index;
  int			is_first;
  int			tmp_path[255];
  void			*graph;
  int			is_next;
  int			coordinate[255];
  char			*msg;
  struct s_position	*next;
}			t_position;

typedef struct		s_scope
{
  void			*scope;
  struct s_scope	*next;
}			t_scope;

int		my_strcmp(char *s, char *s1);
void		my_strcpy(char *s, char *s1);
int		str_to_int(char *str);
t_bunny_ini	*get_ini(const char *file_name);
t_scope		*init_scope(void *scope);
t_scope		*append_scope(t_scope *head, void *scope);
t_scope		*get_scope(t_bunny_ini *ini);
short		init_node_graph(t_position *list, t_position *entity,
				const int pos);
short		append_node_graph(t_position *list, t_position *entity,
				  const int pos);
int		check_proper_graph(t_position *list);
int		produce_graph(t_position *list);
void		my_mensetab_int(int *tab, int len, int value);
void		my_mensetab_char(char *tab, int len, char value);
int		set_entity(void *entity, void *scope, const char *field,
			   const int *infos);
int		get_info(t_position *entity, void *scope);
t_position	*init_graph(void *scope);
t_position	*append_graph(t_position *head, void *scope);
void		free_graph(t_position *list);
int		check_index(t_position *list, unsigned int i,
			    unsigned int len);
t_position	*fill_graph(t_scope *scopes);
t_position	*get_graph(const char *file_name);
void		*make_graph_copy(void *graph);
void		append_two_graph(t_position *to_had_entity, void *graph);
void		complete_graph_path(t_position *graph);
short		is_in_already_in_graph(int *tab, int item);
void		delete_node(t_scope *node, t_scope **head);
void		clean_graph_remove_same(t_position *graph);
void		clean_graph(t_position *graph, int i);
int		can_reach(t_position *entity, const int index);
void		*get_path(t_position *entity, const int index, unsigned int i);
void		*get_path_next(t_position *entity, const int index, int curnt);
int		cursor_aabb_collision(int cursor_x, int cursor_y, int pos_x,
				      int pos_y);
void		display_graph(t_position *graph,
			      t_bunny_pixelarray *bg,
			      t_bunny_pixelarray *pic);
void                    my_blit(t_bunny_pixelarray *dest,
                                t_bunny_pixelarray *ori,
                                t_bunny_position *pos);

#endif /* !POSITION_H_ */
