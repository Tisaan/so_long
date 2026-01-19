/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student->42->fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:05:21 by tseche            #+#    #+#             */
/*   Updated: 2026/01/19 15:40:02 by tseche           ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_sprite(t_sprite *sprite)
{
	if (sprite[0].content)
		free(sprite[0].content);
	if (sprite[1].content)
		free(sprite[1].content);
	if (sprite[2].content)
		free(sprite[2].content);
	if (sprite[3].content)
		free(sprite[3].content);
	if (sprite[4].content)
		free(sprite[4].content);
}

void	init_sprite(t_win_inst *inst)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite) * 5);
	sprite[0].content = mlx_xpm_file_to_image(inst->mlx_instance, COLL_XPM,
			&sprite[0].width, &sprite[0].height);
	sprite[1].content = mlx_xpm_file_to_image(inst->mlx_instance, EMPTY_XPM,
			&sprite[1].width, &sprite[1].height);
	sprite[2].content = mlx_xpm_file_to_image(inst->mlx_instance, EXIT_XPM,
			&sprite[2].width, &sprite[2].height);
	sprite[3].content = mlx_xpm_file_to_image(inst->mlx_instance, WALL_XPM,
			&sprite[3].width, &sprite[3].height);
	sprite[4].content = mlx_xpm_file_to_image(inst->mlx_instance,
			PLAYER_XPM, &sprite[4].width, &sprite[4].height);
	inst->img.sprite = sprite;
	if (!sprite[0].content || !sprite[1].content
		|| !sprite[2].content || !sprite[3].content
		|| !sprite[4].content)
	{
		cleanup(inst);
		call_err(ERROR_OPEN_XPM);
	}
	return ;
}
