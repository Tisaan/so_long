/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:50:52 by marvin            #+#    #+#             */
/*   Updated: 2026/01/13 19:52:25 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*rm_line(char *ret);

char	*read_file(int fd, char *line, char *buff);

char	*get_next_line(int fd, char c);

size_t	ft_strlen(char *src);

char	*ft_strdup(char *src);

char	*ft_strchr(char *src, char lf);

char	*ft_strjoin(char *po, char *pt);

char	*ft_substr(char *src, unsigned int start, size_t len);
#endif