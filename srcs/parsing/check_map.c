/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:04:53 by tseche            #+#    #+#             */
/*   Updated: 2026/01/15 19:56:55 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error_map	is_valid(t_map_info *map)
{
	t_error_map	err;

	if (!is_rectangle(map))
		return (INC_SHAPE);
	if (!properly_walled(map))
		return (INC_WALL);
	err = check_obj(map);
	if (err != NO_ERROR)
		return (err);
	if (map->len > 100 || map->size > 100)
		return (ERROR_SIZE);
	err = floodfill(map);
	return (err);
}

t_map_info	get_map(int fd)
{
	char	**map;
	int		i;
	size_t	obj;
	char	*line;

	map = NULL;
	i = 1;
	line = get_next_line(fd, '\n');
	while (line)
	{
		map = ft_realloc(map, sizeof(char *) * 1);
		if (!map)
		{
			ft_freeptr(map);
			call_err(ERROR_MALLOC);
		}
		map[i - 1] = line;
		free(line);
		line = get_next_line(fd, '\n');
		i++;
	}
	free(line);
	return ((t_map_info){.map = map, .size = i,
		.len = 0, .obj = NULL});
}

bool	get_map_valid(char *name)
{
	int			fd;
	t_map_info	map;
	t_error_map	err;

	if (!str_end_with(name, ".ber"))
		call_err(INC_EXT);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		call_err(ERROR_OPEN);
	map = get_map(fd);
	map.obj = ft_calloc(80, sizeof(size_t));
	if (!map.obj)
	{
		free(map.obj);
		ft_freeptr(map.map);
		call_err(ERROR_MALLOC);
	}
	err = is_valid(&map);
	if (err != NO_ERROR)
	{
		free(map.obj);
		ft_freeptr(map.map);
		call_err(err);
	}
	return (true);
}
