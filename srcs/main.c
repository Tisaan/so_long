/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:26:21 by tseche            #+#    #+#             */
/*   Updated: 2026/01/21 11:22:36 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_win_inst	*inst;

	if (ac != 2)
	{
		write(2, "./so_long <PATH_TO_MAP>", 24);
		return (1);
	}
	inst = malloc(sizeof(t_win_inst));
	if (!inst)
		call_err(ERROR_MALLOC);
	inst->map = get_map_valid(av[1]);
	init_mlx(inst);
	init_sprite(inst);
	inst->img.height = inst->map.size * 32;
	inst->img.width = inst->map.len * 32;
	set_hook(inst);
	draw(inst, 0);
	mlx_loop(inst->mlx_instance);
	return (0);
}
