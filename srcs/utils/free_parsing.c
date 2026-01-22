/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:20:57 by tseche            #+#    #+#             */
/*   Updated: 2026/01/22 18:08:16 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_parsing(t_map_info *map, t_win_inst *inst, t_error_map err)
{
	if (inst)
		free(inst);
	if (map->map)
		ft_freeptr((void **)map->map);
	if (map->obj)
		free(map->obj);
	call_err(err);
}
