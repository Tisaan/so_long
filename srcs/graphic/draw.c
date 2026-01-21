/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:58:14 by tseche            #+#    #+#             */
/*   Updated: 2026/01/21 14:31:25 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <regex.h>

void	render(t_win_inst *inst, t_sprite sp, size_t x, size_t y)
{
	mlx_put_image_to_window(inst->mlx_instance, inst->win, sp.content, (y * sp.width), (x * sp.height));
}

void	render_map(t_win_inst *inst, size_t x, size_t y)
{
	char	param;

	param = inst->map.map[x][y];
	if (param == 'C')
		render(inst, inst->img.sprite[2], x, y);
	else if (param == '1')
		render(inst, inst->img.sprite[0], x, y);
	else if (param == '0')
		render(inst, inst->img.sprite[1], x, y);
	else if (param == 'E')
		render(inst, inst->img.sprite[4], x, y);
	else if (param == 'P')
		render(inst, inst->img.sprite[3], x, y);
}

void	update_player(t_move move, size_t *x, size_t *y)
{
	if (move == UP)
		*x += -1;
	else if (move == DOWN)
		*x += 1;
	else if (move == LEFT)
		*y += -1;
	else if (move == RIGHT)
		*y += 1;
}

void	update_map(t_win_inst *inst, t_move move)
{
	size_t	x;
	size_t	y;

	x = inst->map.player_x;
	y = inst->map.player_y;
	update_player(move, &x, &y);
	if (inst->map.map[x][y] == '1')
		return ;
	ft_printf("nombre de move:%d\n", inst->nb_move);
	inst->nb_move++;
	if (inst->map.on_door)
	{
		inst->map.on_door = 0;
		inst->map.map[inst->map.player_x][inst->map.player_y] = 'E';
	}
	else
		inst->map.map[inst->map.player_x][inst->map.player_y] = '0';
	if (inst->map.map[x][y] == 'E')
		inst->map.on_door = 1;
	else if (inst->map.map[x][y] == 'C')
		inst->map.obj_rest--;
	inst->map.map[x][y] = 'P';
	inst->map.player_x = x;
	inst->map.player_y = y;
}

void	draw(t_win_inst *inst, t_move move)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (move)
		update_map(inst, move);
	while (x < inst->map.size)
	{
		y = 0;
		while (y < inst->map.len)
		{
			render_map(inst, x, y);
			y++;
		}
		x++;
	}
	inst->cam_x = inst->map.player_x - inst->img.width / 2;
	inst->cam_x = inst->map.player_y - inst->img.height / 2;
	if (inst->map.on_door && inst->map.obj_rest == 0)
	{
		ft_printf("You Win\n");
		cleanup(inst);
		exit(0);
	}
}
