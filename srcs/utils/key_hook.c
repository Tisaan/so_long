/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:51:34 by tseche            #+#    #+#             */
/*   Updated: 2026/01/18 19:53:15 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_hook(int keycode, t_win_inst *inst)
{
	if (keycode == )
	return (0);
};

void	set_hook(t_win_inst *inst)
{
	mlx_hook(inst->win, 17, 0, close_window, inst);
	mlx_key_hook(inst->win, key_hook, inst);
	mlx_mouse_hook(inst->win, mouse_hook, inst);
}