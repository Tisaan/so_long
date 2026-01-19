/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:58:14 by tseche            #+#    #+#             */
/*   Updated: 2026/01/19 17:02:44 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render(t_win_inst *inst, t_sprite sp, size_t x, size_t y)
{
	mlx_put_image_to_window(
		inst->mlx_instance, inst->win, inst->img.addr,
		x * sp.height, y * sp.width);
}

void	get_map(t_win_inst *inst, size_t x, size_t y)
{
	char	param;

	param = inst->map.map[x][y];
	if (param == 'C')
	{
		inst->map.map[x][y] = '0';
		render(inst, inst->img.sprite[2], x, y);
	}
	else if (param == '1')
		render(inst, inst->img.sprite[0], x, y);
	else if (param == '0')
		render(inst, inst->img.sprite[1], x, y);
	else if (param == 'E')
		render(inst, inst->img.sprite[4], x, y);
	else if (param == 'P')
		render(inst, inst->img.sprite[3], x, y);
}

void	draw(t_win_inst *inst, t_move move)
{
	size_t	x;
	size_t	y;
	while (y < inst->map.size)
	{
		x = 0;
		while (x < inst->map.len)
		{
			get_map(inst, x, y);
			x++;
		}
		y++;
	}
	
}
