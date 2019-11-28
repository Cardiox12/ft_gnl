/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:20:52 by bbellavi          #+#    #+#             */
/*   Updated: 2019/11/28 17:59:49 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char			*concat;
	char			*begin;

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

t_buf	*init_buffer(int fd)
{
	t_buf	*buf;

	buf = (t_buf*)malloc(sizeof(t_buf));
	if (buf == NULL)
		return (NULL);
	buf->dynamic = NULL;
	buf->buffer[0] = '\0';
	buf->fd = fd;
	buf->next = NULL;
	return (buf);
}

t_buf	*manage_buffer(t_buf **origin, int fd)
{
	t_buf	*buf;
	t_buf	*tmp;

	buf = NULL;
	if (*origin == NULL)
		*origin = init_buffer(fd);
	else
	{
		tmp = *origin;
		while (tmp && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp != NULL)
			return (tmp);
		else
		{
			tmp = *origin;
			while (tmp->next != NULL)
				tmp = tmp->next;
			if ((tmp->next = init_buffer(fd)) == NULL)
				return (NULL);
			return (tmp->next);
		}
	}
	return (buf);
}
