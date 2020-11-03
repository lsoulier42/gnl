/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:16:18 by louise            #+#    #+#             */
/*   Updated: 2020/11/03 17:22:54 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			set_begin_line(char *buff, char **line_begin)
{
	int		i;
	int		offset;
	int		nb_char;

	i = -1;
	offset = 0;
	nb_char = 0;
	if (*buff != '\0')
	{
		while (offset < BUFFER_SIZE && buff[offset] != '\n')
			offset++;
		if (buff[offset] == '\n')
			offset++;
		while (offset + nb_char < BUFFER_SIZE && buff[offset + nb_char]
			&& buff[offset + nb_char] != '\n')
			nb_char++;
	}
	if (!(*line_begin = (char*)malloc(sizeof(char) * (nb_char + 1))))
		return (0);
	while (++i < nb_char)
		(*line_begin)[i] = buff[offset + i];
	(*line_begin)[i] = '\0';
	if (offset + nb_char < BUFFER_SIZE && buff[offset + nb_char] == '\n')
		return (offset);
	return (0);
}

char		*join_buff(char *line, char *buff, int buff_len)
{
	char	*new;
	int		i;
	int		j;
	int		line_len;

	i = -1;
	j = -1;
	line_len = 0;
	while (line[line_len])
		line_len++;
	if (!(new = (char*)malloc(sizeof(char) * (line_len + buff_len + 1))))
		return (NULL);
	while (++i < line_len)
		new[i] = line[i];
	free(line);
	while (++j < buff_len)
		new[i + j] = buff[j];
	new[i + j] = '\0';
	return (new);
}

int			move_buff(char *buff, int offset)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (offset + ++i < BUFFER_SIZE)
		buff[i] = buff[offset + i];
	while (i < BUFFER_SIZE)
		buff[i++] = '\0';
	while (buff[++j])
		if (buff[j] == '\n')
			return (1);
	return (0);
}

int			read_file(int fd, char *buff, char **line)
{
	int len;
	int read_val;

	while ((read_val = read(fd, buff, BUFFER_SIZE)) != 0)
	{
		if (read_val == -1)
			return (-1);
		len = 0;
		while (len < read_val && buff[len] != '\n')
			len++;
		if (read_val < BUFFER_SIZE)
			buff[read_val] = '\0';
		*line = join_buff(*line, buff, len);
		if (len != BUFFER_SIZE && len != read_val)
			return (1);
	}
	return (0);
}
