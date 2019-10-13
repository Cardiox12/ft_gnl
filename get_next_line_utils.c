/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:20:52 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/13 04:33:55 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *uchar_s;

	uchar_s = s;
	while (n-- > 0)
		*uchar_s++ = 0;
}

size_t	ft_strlen(const char *str)
{
	const char *final_str = str;

	while (*str != '\0')
		str++;
	return (str - final_str);
}
               
char	*ft_strnew(size_t size)
{
	char *string;

	string = malloc(size);
	if (string == NULL)
		return (NULL);
	ft_bzero(string, size);
	return (string);
}

char	*ft_strdup(const char *s1)
{
	char *duplicate;
	char *begin;

	duplicate = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (duplicate == NULL)
		return (NULL);
	begin = duplicate;
	while (*s1 != '\0')
		*duplicate++ = *s1++;
	*duplicate = '\0';
	return (begin);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char 			*begin;
	char			*concat;

	concat = ft_strnew(s1_len + s2_len + 1);
	if (concat == NULL)
		return (NULL);
	begin = concat;
	while (*s1)
		*concat++ = *s1++;
	while (*s2)
		*concat++ = *s2++;
	return (begin);
}
