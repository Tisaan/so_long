/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:06:31 by tseche            #+#    #+#             */
/*   Updated: 2026/01/18 18:20:48 by tseche           ###   ########.fr       */
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
	inst->win = mlx_new_window(inst->mlx_instance, WIDTH, HEIGHT, "Fract-0l");
	if (!inst->win)
	{
		free(inst->mlx_instance);
		ft_freeptr((void **)inst->map.map);
		call_err(ERROR_MALLOC);
	}
	inst->img.img = mlx_new_image(inst->mlx_instance, WIDTH, HEIGHT);
	if (!inst->img.img)
	{
		free(inst->win);	
		free(inst->mlx_instance);
		ft_freeptr((void **)inst->map.map);
		call_err(ERROR_MALLOC);
	}
	inst->img.addr = mlx_get_data_addr(inst->img.img,
			&inst->img.bits_per_pixel, &inst->img.line_length, &inst->img.endian);
}
