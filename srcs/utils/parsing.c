/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:47:39 by tseche            #+#    #+#             */
/*   Updated: 2026/01/15 20:21:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error_map	floodfill(char **aux, int j, int i)
{
}

bool	is_rectangle(t_map_info *map)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(map->map[0]);
	while (i < map->size)
	{
		if (ft_strlen(map->map[i]) != len)
			return (false);
		j = 0;
		while (j < len)
		{
			if (ft_isoneof(map->map[i][j], "CEP"))
				map->obj[map->map[i][j]]++;
			j++;
		}
		i++;
	}
	map->len = len;
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

bool	properly_walled(t_map_info *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if ((!i || !map->map[i + 1]) && is_diff_than(map->map[i], "1"))
			return (false);
		else if ((i && map->map[i + 1])
			&& (map->map[i][0] != '1'
			|| map->map[i][ft_strlen(map->map[i])] != '1'))
			return (false);
		i++;
	}
	return (true);
}

char	**cp_map(t_map_info *map)
{
	char	**cmap;
	size_t	i;

	cmap = malloc(sizeof(char *) * map->size);
	if (!cmap)
		return (NULL);
	i = 0;
	while (i < map->size)
	{
		cmap[i] = ft_strdup(map->map[i]);
		if (!cmap)
		{
			ft_freeptr(cmap);
			return (NULL);
		}
		i++;
	}
	return (cmap);
}
