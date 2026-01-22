/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:47:39 by tseche            #+#    #+#             */
/*   Updated: 2026/01/22 15:48:19 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	floodfill(t_map_info *map, char **aux, int i, int j)
{
	if (aux[i][j] == '1' || aux[i][j] == 'V')
		return ;
	if (ft_isoneof(aux[i][j], "CEP"))
	{
		if (aux[i][j] == 'C')
			map->obj_rest++;
		map->obj[(int)aux[i][j]]--;
	}
	aux[i][j] = 'V';
	floodfill(map, aux, i + 1, j);
	floodfill(map, aux, i - 1, j);
	floodfill(map, aux, i, j + 1);
	floodfill(map, aux, i, j - 1);
	return ;
}

bool	is_rectangle(t_map_info *map)
{
	size_t	i;
	size_t	j;

	map->len = ft_strlen(map->map[0]) - 1;
	i = 0;
	while (i < map->size)
	{
		if (ft_strlen(map->map[i]) - 1 != map->len)
			return (false);
		j = 0;
		while (j < map->len)
		{
			if (ft_isoneof(map->map[i][j], "CEP"))
				map->obj[(int)map->map[i][j]]++;
			if (map->map[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
			}
			j++;
		}
		i++;
	}
	return (true);
}

t_error_map	rep_error(size_t coll, size_t finish, size_t start)
{
	if (coll < 1)
		return (NOT_ENO_COLL);
	else if (start < 1)
		return (NOT_ENO_STRT);
	else if (start > 1)
		return (TOO_MUCH_STRT);
	else if (finish < 1)
		return (NOT_ENO_FINISH);
	else if (finish > 1)
		return (TOO_MUCH_FINISH);
	return (NO_ERROR);
}

bool	properly_walled(t_map_info *map, t_win_inst *inst)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (is_diff_than(map->map[i], "01CEP"))
			free_parsing(map, inst, INC_CHAR);
		if ((!i || !map->map[i + 1]) && is_diff_than(map->map[i], "1"))
			return (false);
		else if ((i && map->map[i + 1])
			&& (map->map[i][0] != '1' || map->map[i][map->len - 1] != '1'))
			return (false);
		i++;
	}
	return (true);
}

char	**cp_map(t_map_info *map)
{
	char	**cmap;
	size_t	i;

	cmap = malloc(sizeof(char *) * (map->size + 1));
	if (!cmap)
		return (NULL);
	i = 0;
	while (i < map->size)
	{
		cmap[i] = ft_strdup(map->map[i]);
		if (!cmap)
		{
			ft_freeptr((void **)cmap);
			return (NULL);
		}
		i++;
	}
	cmap[i] = NULL;
	return (cmap);
}
