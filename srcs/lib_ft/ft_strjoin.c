/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:45:38 by tseche            #+#    #+#             */
/*   Updated: 2026/01/22 18:08:44 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates memory (using malloc(3)) and returns a
new string, which is the result of concatenating
’s1’ and ’s2’.
*/
char	*ft_strjoin(char *s1, char *s2, int to_free)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, s1, ft_strlen(s1) + 1);
	ft_strlcat(ptr, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	if (to_free == 2)
	{
		free(s1);
		free(s2);
	}
	else if (to_free == 0)
		free(s1);
	else if (to_free == 1)
		free(s2);
	return (ptr);
}

/*
int main()
{
	char *s1 = "my favorite animal is";
 	char *s2 = " ";
 	char *s3 = "the nyancat";
 	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);
	
	
}*/