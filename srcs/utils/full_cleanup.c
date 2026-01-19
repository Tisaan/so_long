/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:11:32 by tseche            #+#    #+#             */
/*   Updated: 2026/01/19 15:29:03 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	cleanup(t_win_inst *inst)
{
	free_sprite(inst->img.sprite);
	ft_freeptr((void **)inst->map.map);
	free(inst->img.img);
	free(inst->win);
	free(inst->mlx_instance);
	free(inst);
}
