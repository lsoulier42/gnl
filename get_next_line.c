/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:46:57 by louise            #+#    #+#             */
/*   Updated: 2020/11/01 01:19:11 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE] = "";
	static int	prev_fd = 0;
	int			offset;

	if (fd < 0 || !line)
		return (-1);
	if (fd != prev_fd)
		*buff = '\0';
	prev_fd = fd;
	offset = set_begin_line(buff, line);
	if (offset == 0)
		return (read_file(fd, buff, line));
	else
		return (move_buff(buff, offset));
}
