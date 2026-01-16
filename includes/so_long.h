/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:05:03 by tseche            #+#    #+#             */
/*   Updated: 2026/01/16 19:41:54 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../srcs/gnl/get_next_line.h"
# include "../srcs/lib_ft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>

bool	str_end_with(char *s, char *pattern);

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
[ERROR_MALLOC] = "Erreur malloc\n",
};

typedef struct s_map_info
{
	char	**map;
	size_t	size;
	size_t	len;
	size_t	*obj;
	size_t	strt_x;
	size_t	strt_y;
}				t_map_info;

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}				t_pos;

void	call_err(t_error_map err);

bool	is_rectangle(t_map_info *map);

bool	properly_walled(t_map_info *map);
//est mal indent mais qu'importe les tab is est mal indente
t_error_map	check_obj(t_map_info *map);

char	**cp_map(t_map_info *map);

void	floodfill(t_map_info *map, char **aux, int j, int i);

t_error_map	rep_error(size_t coll, size_t finish, size_t start);

t_map_info	get_map_valid(char *name);

#endif