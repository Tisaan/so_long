/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:08:02 by tseche            #+#    #+#             */
/*   Updated: 2026/01/15 19:20:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	call_err(t_error_map err)
{
	if (err < ERROR_MAX)
	{
		perror(g_errors[err]);
		exit(1);
	}
	perror("WTF bro, you're giving an unknown error,"
		"do you know how to code?");
	exit(1);
}
