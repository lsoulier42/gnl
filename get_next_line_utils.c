/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:55:48 by louise            #+#    #+#             */
/*   Updated: 2020/10/25 15:20:17 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (src)
	{
		while (src[src_len])
			src_len++;
		if (dstsize > 0)
		{
			while (src[i] && (i < (dstsize - 1)))
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = 0;
	srclen = 0;
	i = 0;
	while (dst[dstlen])
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstsize == 0 || dstsize <= dstlen)
		return (srclen + dstsize);
	while (i < srclen && i < dstsize - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

int 	get_in_buff(char **line, char buff[BUFFER_SIZE + 1], int end_of_file)
{
	int len;
	int end_of_line;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	end_of_line = buff[len] == '\n';
	*line = (char*)malloc((len + 1) * sizeof(char));
	if (!(*line))
		return (-1);
	ft_strlcpy(*line, buff, len + 1);
	clear_buff(buff, len, end_of_line, end_of_file);
	return (end_of_line);
}

void 	clear_buff(char buff[BUFFER_SIZE + 1], int to_endl, int end_of_line, int end_of_file)
{
	int i;

	i = -1;
	if (end_of_line)
		ft_strlcpy(buff, buff + to_endl + 1, BUFFER_SIZE - to_endl);
	else if (end_of_file)
		ft_strlcpy(buff, buff + to_endl, BUFFER_SIZE - to_endl + 1);
	else
	{
		while (++i <= BUFFER_SIZE)
			buff[i] = '\0';
	}
}

int 	fill_line(char **line, char buff[BUFFER_SIZE + 1], int end_of_file)
{
	int		len;
	int		to_copy;
	char	*new_line;
	int 	end_of_line;

	len = 0;
	to_copy = 0;
	while (*line && (*line)[len])
		len++;
	while (buff[to_copy] && buff[to_copy] != '\n')
		to_copy++;
	end_of_line = buff[to_copy] == '\n';
	if(!(new_line = (char*)malloc((len + to_copy + 1) * sizeof(char))))
		return (-1);
	*new_line = '\0';
	if (*line)
	{
		ft_strlcpy(new_line, *line, len + 1);
		free(*line);
	}
	ft_strlcat(new_line, buff, len + to_copy + 1);
	*line = new_line;
	clear_buff(buff, to_copy, end_of_line, end_of_file);
	return (end_of_line);
}