/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:20:52 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/13 21:33:37 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char *final_str = str;

	while (*str != '\0')
		str++;
	return (str - final_str);
}

char	*ft_strndup(const char *s, size_t len)
{
	char *string;
	char *begin;

	string = malloc(len + 1);
	if (string == NULL)
		return (NULL);
	begin = string;
	while (len-- != 0 && *s)
		*string++ = *s++;
	*string = '\0';
	return (begin);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char 			*begin;
	char			*concat;

	concat = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (concat == NULL)
		return (NULL);
	begin = concat;
	while (*s1)
		*concat++ = *s1++;
	while (*s2)
		*concat++ = *s2++;
	*concat = '\0';
	return (begin);
}
