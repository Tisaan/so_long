/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_end_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:11:30 by tseche            #+#    #+#             */
/*   Updated: 2026/01/15 19:01:38 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	str_end_with(char *s, char *pattern)
{
	s += ft_strlen(s) - ft_strlen(pattern);
	while (*s && *s == *pattern && s++ && pattern ++)
		;
	if (!*s)
		return (true);
	return (false);
}
