/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:51:34 by tseche            #+#    #+#             */
/*   Updated: 2026/01/21 15:10:06 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_hook(int keycode, t_win_inst *inst)
{
	if (keycode == 65307)
	{
		cleanup(inst);
		exit(0);
	}
	else if (keycode == 65361)
		draw(inst, LEFT);
	else if (keycode == 65362)
		draw(inst, UP);
	else if (keycode == 65363)
		draw(inst, RIGHT);
	else if (keycode == 65364)
		draw(inst, DOWN);
	return (0);
}

int	exit_(t_win_inst *inst)
{
	cleanup(inst);
	exit(0);
	return (1);
}

void	set_hook(t_win_inst *inst)
{
	mlx_hook(inst->win, 17, 0, exit_, inst);
	mlx_key_hook(inst->win, key_hook, inst);
}
