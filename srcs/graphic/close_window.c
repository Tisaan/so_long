/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:41:41 by tseche            #+#    #+#             */
/*   Updated: 2026/01/18 18:44:50 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_win_inst *inst)
{
	if (inst->img.img)
		mlx_destroy_image(inst->mlx_instance, inst->img.img);
	if (inst->win)
		mlx_destroy_window(inst->mlx_instance, inst->win);
	if (inst->mlx_instance)
	{
		mlx_destroy_display(inst->mlx_instance);
		free(inst->mlx_instance);
	}
	exit(0);
	return (0);
}