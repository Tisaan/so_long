/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:08:02 by tseche            #+#    #+#             */
/*   Updated: 2026/01/16 19:44:47 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	call_err(t_error_map err)
{
	if (err < ERROR_MAX)
	{
		write(2, "Error\n", 6);
		write(2, g_errors[err], ft_strlen(g_errors[err]));
		exit(0);
	}
	write(2, "Error\n", 6);
	write(2, "WTF bro, you're giving an unknown error,"
		"do you know how to code?\n", 66);
	exit(0);
}
