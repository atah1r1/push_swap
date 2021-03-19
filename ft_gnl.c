/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:06:24 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/19 15:30:20 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_gnl(int fd, char **line)
{
	char	*buffer;
	int		n_bytes;

	if (!line || !(buffer = (char *)malloc(2))
	|| !(*line = (char *)malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	while ((n_bytes = read(fd, buffer, 1)) > 0)
	{
		buffer[1] = '\0';
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buffer, 1, 0);
	}
	free(buffer);
	return (n_bytes);
}