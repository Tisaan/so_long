/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:05:03 by tseche            #+#    #+#             */
/*   Updated: 2026/01/21 14:10:46 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../srcs/gnl/get_next_line.h"
# include "../srcs/lib_ft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>

# define WALL_XPM "./textures/wall.xpm"
# define EMPTY_XPM "./textures/empty.xpm"
# define COLL_XPM "./textures/collectible.xpm"
# define EXIT_XPM "./textures/exit.xpm"
# define PLAYER_XPM "./textures/player.xpm"

typedef enum e_error_map
{
	NO_ERROR,
	INC_EXT,
	INC_WALL,
	INC_CHAR,
	INC_SHAPE,
	NOT_ENO_STRT,
	TOO_MUCH_STRT,
	NOT_ENO_COLL,
	NOT_ENO_FINISH,
	TOO_MUCH_FINISH,
	NOT_REACH_COLL,
	NOT_REACH_FINISH,
	ERROR_SIZE,
	ERROR_OPEN,
	ERROR_OPEN_XPM,
	ERROR_MALLOC,
	ERROR_MAX,
}		t_error_map;

static const char	*g_errors[ERROR_MAX] = {
[NO_ERROR] = ("WTF an error has been"
		"thrown, but no error was detected\n"),
[INC_EXT] = "the map provided is not a .ber file\n",
[INC_WALL] = "The wall hasn't been properly walled\n",
[INC_CHAR] = "An unrecognize character has been found\n",
[INC_SHAPE] = "The Map is not a rectangle\n",
[NOT_ENO_STRT] = "The Map contains no starting point\n",
[TOO_MUCH_STRT] = "The map cointains too much starting point\n",
[NOT_ENO_COLL] = "The Map contains no collectible\n",
[NOT_ENO_FINISH] = "The Map contains no exit\n",
[TOO_MUCH_FINISH] = "The map contain too much finish\n",
[NOT_REACH_COLL] = "The Map contains a not reachable collectible\n",
[NOT_REACH_FINISH] = "The Map contains a not reachable exit\n",
[ERROR_SIZE] = "The map is limited to 100 * 100 du to stack limitation\n",
[ERROR_OPEN] = "A file couldn't be opened\n",
[ERROR_OPEN_XPM] = "A XPM file couldn't be opened\n",
[ERROR_MALLOC] = "Erreur malloc\n",
};

typedef enum e_move
{
	UP = 1,
	DOWN,
	RIGHT,
	LEFT,
}			t_move;

typedef struct s_map_info
{
	char	**map;
	size_t	size;
	size_t	len;
	size_t	*obj;
	size_t	player_x;
	size_t	player_y;
	size_t	on_door;
	int		obj_rest;
}				t_map_info;

typedef struct s_sprite
{
	void	*content;
	int		height;
	int		width;
}				t_sprite;

//sprite :
// [0] wall
// [1] empty
// [2] coll
// [3] player
// [4] exit
typedef struct s_img
{
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				offset;
	int				height;
	int				width;
	void			*tile;
	t_sprite		*sprite;
}				t_img;

typedef struct s_win_inst
{
	void		*mlx_instance;
	void		*win;
	t_img		img;
	t_map_info	map;
	size_t		nb_move;
	int			cam_x;
	int			cam_y;
}				t_win_inst;

t_error_map		check_obj(t_map_info *map);

bool			str_end_with(char *s, char *pattern);

//          [error reporting]
void			call_err(t_error_map err);

//          [parsing]
bool			is_rectangle(t_map_info *map);

bool			properly_walled(t_map_info *map);
//est mal indent mais qu'importe les tab is est mal indente

char			**cp_map(t_map_info *map);

void			floodfill(t_map_info *map, char **aux, int j, int i);

t_error_map		rep_error(size_t coll, size_t finish, size_t start);

t_map_info		get_map_valid(char *name);

void			cleanup(t_win_inst *inst);

//           [mlx]
int				key_hook(int keycode, t_win_inst *inst);
void			init_mlx(t_win_inst *inst);
int				close_window(t_win_inst *inst);

void			set_hook(t_win_inst *inst);

//          [Graphic]
void			free_sprite(t_win_inst *inst, t_sprite *sprite);
void			draw(t_win_inst *inst, t_move move);
int				close_window(t_win_inst *inst);
void			init_sprite(t_win_inst *inst);

#endif