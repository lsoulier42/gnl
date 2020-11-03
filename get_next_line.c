/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:46:57 by louise            #+#    #+#             */
/*   Updated: 2020/11/03 17:23:57 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE] = "";
	static int	prev_fd = 0;
	int			offset;
	int			gnl_return;

	if (fd < 0 || !line)
		return (-1);
	if (fd != prev_fd)
		*buff = '\0';
	prev_fd = fd;
	offset = set_begin_line(buff, line);
	if (offset == 0)
		gnl_return = read_file(fd, buff, line);
	else
		gnl_return = move_buff(buff, offset);
	if (gnl_return == -1)
		*line = NULL;
	return (gnl_return);
}
