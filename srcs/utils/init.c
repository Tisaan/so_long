/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:06:31 by tseche            #+#    #+#             */
/*   Updated: 2026/01/22 16:12:26 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_mlx(t_win_inst *inst)
{
	inst->mlx_instance = mlx_init();
	if (!inst->mlx_instance)
	{
		ft_freeptr((void **)inst->map.map);
		call_err(ERROR_MALLOC);
	}
	inst->win = mlx_new_window(inst->mlx_instance,
			inst->map.len * 32, inst->map.size * 32, "Fract-0l");
	if (!inst->win)
	{
		free(inst->mlx_instance);
		ft_freeptr((void **)inst->map.map);
		call_err(ERROR_MALLOC);
	}
	inst->nb_move = 0;
}
