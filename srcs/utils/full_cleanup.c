/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:11:32 by tseche            #+#    #+#             */
/*   Updated: 2026/01/21 11:25:01 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	cleanup(t_win_inst *inst)
{
	free_sprite(inst, inst->img.sprite);
	ft_freeptr((void **)inst->map.map);
	mlx_destroy_window(inst->mlx_instance, inst->win);
	mlx_destroy_display(inst->mlx_instance);
	free(inst->mlx_instance);
	free(inst);
}
