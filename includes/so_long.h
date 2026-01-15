/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:05:03 by tseche            #+#    #+#             */
/*   Updated: 2026/01/15 19:25:02 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./srcs/gnl/get_next_line.h"
# include "./srcs/lib_ft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

bool	str_end_with(char *s, char *pattern);

static const char	*g_errors[ERROR_MAX] = {
[NO_ERROR] = "WTF an error has been"
	"thrown, but no error was detected",
[INC_EXT] = "the map provided is not a .ber file",
[INC_WALL] = "The wall hasn't been properly walled",
[INC_CHAR] = "An unrecognize character has been found",
[INC_SHAPE] = "The Map is not a rectangle",
[NOT_ENO_STRT] = "The Map contains no starting point",
[TOO_MUCH_STRT] = "The map cointains too much starting point",
[NOT_ENO_COLL] = "The Map contains no collectible",
[NOT_ENO_FINISH] = "The Map contains no exit",
[TOO_MUCH_FINISH] = "The map contain too much finish",
[NOT_REACH_COLL] = "The Map contains a not reachable collectible",
[NOT_REACH_FINISH] = "The Map contains a not reachable exit",
[ERROR_SIZE] = "The map is limited to 100 * 100 du to stack limitation",
[ERROR_OPEN] = "A file couldn't be opened",
[ERROR_MALLOC] = "Erreur malloc",
};

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

typedef struct s_map_info
{
	char	**map;
	size_t	size;
	size_t	len;
	size_t	*obj;
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

#endif