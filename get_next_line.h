/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:28:32 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/13 04:16:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);

#	endif
