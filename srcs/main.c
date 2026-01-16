/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:26:21 by tseche            #+#    #+#             */
/*   Updated: 2026/01/16 19:39:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_map_info	map;

	if (ac != 2)
	{
		write(2, "./so_long <PATH_TO_MAP>", 24);
		return (1);
	}
	map = get_map_valid(av[1]);
	return (0);
}