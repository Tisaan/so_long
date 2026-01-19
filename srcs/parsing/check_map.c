/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:04:53 by tseche            #+#    #+#             */
/*   Updated: 2026/01/19 14:53:10 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_size(char *s)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		call_err(ERROR_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

t_error_map	is_valid(t_map_info *map)
{
	t_error_map	err;
	char		**aux;

	if (!is_rectangle(map))
		return (INC_SHAPE);
	if (!properly_walled(map))
		return (INC_WALL);
	if (map->len > 100 || map->size > 100)
		return (ERROR_SIZE);
	err = rep_error(map->obj['C'], map->obj['E'], map->obj['P']);
	if (err != NO_ERROR)
	{
		free(map->obj);
		ft_freeptr((void **)map->map);
		call_err(err);
	}
	aux = cp_map(map);
	floodfill(map, aux, map->strt_x, map->strt_y);
	ft_freeptr((void **)aux);
	err = check_obj(map);
	return (err);
}

void	get_map(int fd, char *s, t_map_info *map)
{
	int		i;
	char	*tmp;

	i = 0;
	map->map = malloc(sizeof(char *) * (get_size(s) + 1));
	if (!map)
		call_err(ERROR_MALLOC);
	map->map[0] = get_next_line(fd);
	while (map->map[i++])
		map->map[i] = get_next_line(fd);
	i -= 2;
	if (!str_end_with(map->map[i], "\n"))
	{
		tmp = map->map[i];
		map->map[i] = ft_strjoin(map->map[i], "\n");
		free(tmp);
		if (!map->map[i])
			call_err(ERROR_MALLOC);
	}
	close(fd);
	map->size = i + 1;
}

t_map_info	get_map_valid(char *name)
{
	int			fd;
	t_map_info	map;
	t_error_map	err;

	if (!str_end_with(name, ".ber"))
		call_err(INC_EXT);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		call_err(ERROR_OPEN);
	ft_bzero(&map, sizeof(t_map_info));
	get_map(fd, name, &map);
	map.obj = ft_calloc(256, sizeof(size_t));
	if (!map.obj)
	{
		ft_freeptr((void **)map.map);
		call_err(ERROR_MALLOC);
	}
	err = is_valid(&map);
	free(map.obj);
	if (err != NO_ERROR)
	{
		ft_freeptr((void **)map.map);
		call_err(err);
	}
	return (map);
}

t_error_map	check_obj(t_map_info *map)
{
	if (!map->obj['C'] && !map->obj['E'] && !map->obj['P'])
		return (NO_ERROR);
	if (map->obj['C'])
		return (NOT_REACH_COLL);
	else if (map->obj['E'])
		return (NOT_REACH_FINISH);
	return (ERROR_MAX);
}
