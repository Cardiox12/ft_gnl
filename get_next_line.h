/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:28:32 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/13 04:45:23 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#   define NEWLINE '\n'

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);


#	endif
