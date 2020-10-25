/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:53:51 by louise            #+#    #+#             */
/*   Updated: 2020/10/25 15:08:58 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		get_next_line(int fd, char **line);
int 	fill_line(char **line, char buff[BUFFER_SIZE + 1], int end_of_file);
int 	get_in_buff(char **line, char buff[BUFFER_SIZE + 1], int end_of_file);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void 	clear_buff(char buff[BUFFER_SIZE + 1], int to_endl, int end_of_line, int end_of_file);
#endif
