/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:09:11 by bbellavi          #+#    #+#             */
/*   Updated: 2019/11/27 17:12:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_BONUS_H
#	define GET_NEXT_LINE_BONUS_H

#	define NEWLINE '\n'

#	define SUCCESS 1
#	define ERROR -1
#	define END_OF_FILE 0
#	define NOT_FOUND -1
#	define CONTINUE 2
=======
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:28:32 by bbellavi          #+#    #+#             */
/*   Updated: 2019/11/17 18:01:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#   define NEWLINE '\n'

#   define SUCCESS 1
#   define ERROR -1
#   define END_OF_FILE 0
#   define NOT_FOUND -1
#   define CONTINUE 2
>>>>>>> finished

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

<<<<<<< HEAD
typedef struct		s_buf
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	char			*dynamic;
	struct s_buf	*next;
}					t_buf;

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strndup(const char *s, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
t_buf				*manage_buffer(t_buf **origin, int fd);
=======
typedef struct  s_buf
{
    int             fd;
    char            buffer[BUFFER_SIZE + 1];
    char            *dynamic;
    struct  s_buf   *next;
}               t_buf;

int         get_next_line(int fd, char **line);
size_t      ft_strlen(const char *str);
char        *ft_strjoin(char const *s1, char const *s2);
char        *ft_strndup(const char *s, size_t len);
char        *ft_strncpy(char *dst, const char *src, size_t len);
t_buf       *manage_buffer(t_buf **origin, int fd);
>>>>>>> finished

#	endif
