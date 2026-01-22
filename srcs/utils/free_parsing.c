/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:20:57 by tseche            #+#    #+#             */
/*   Updated: 2026/01/21 16:28:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_parsing(t_map_info *map, t_win_inst *inst, t_error_map err)
{
	free(inst);
	ft_freeptr((void **)map->map);
	call_err(err);
}