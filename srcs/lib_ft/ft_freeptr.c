/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:09:06 by tseche            #+#    #+#             */
/*   Updated: 2026/01/16 20:30:05 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freeptr(void **ptr)
{
	void	**cp;

	cp = ptr;
	while (*(unsigned char **)ptr)
		free(*(unsigned char **)ptr++);
	free(cp);
}
