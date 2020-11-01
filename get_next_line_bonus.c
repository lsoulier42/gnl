/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 23:46:57 by louise            #+#    #+#             */
/*   Updated: 2020/11/01 01:59:39 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	remove_fd(t_list_file **first, t_list_file *current)
{
	t_list_file *previous;

	previous = *first;
	if (previous != current)
	{
		while (previous->next != current)
			previous = previous->next;
		previous->next = current->next;
	}
	else
		*first = current->next;
	free(current);
}

int		get_next_line(int fd, char **line)
{
	static t_list_file	*first = NULL;
	t_list_file			*current;
	int					offset;
	int					gnl_return;

	if (fd < 0 || !line)
		return (-1);
	current = get_or_put_buffer(fd, &first);
	offset = set_begin_line(current->buff, line);
	if (offset == 0)
		gnl_return = read_file(fd, current->buff, line);
	else
		gnl_return = move_buff(current->buff, offset);
	if (gnl_return == 0)
		remove_fd(&first, current);
	return (gnl_return);
}
