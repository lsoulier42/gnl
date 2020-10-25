/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:53:29 by louise            #+#    #+#             */
/*   Updated: 2020/10/25 16:34:03 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1] = "";
	static int 	end_of_file = 0;
	int			end_of_line;
	int 		r_ret;

	if (fd < 0 || !line)
		return (-1);
	end_of_line = 0;
	*line = NULL;
	if (*buff)
		end_of_line = get_in_buff(line, buff, end_of_file);
	while (!end_of_file && !end_of_line)
	{
		r_ret = read(fd, buff, BUFFER_SIZE);
		if (r_ret == -1 || end_of_line == -1)
			return (-1);
		buff[r_ret] = '\0';
		end_of_file = r_ret == 0;
		if (!end_of_file)
			end_of_line = fill_line(line, buff, end_of_file);
	}
	return (end_of_file == 1 && !(*buff) ? 0 : 1);
}