/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:18:14 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/29 11:31:37 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->top - 1)
	{
		if (a->items[i] > a->items[i + 1])
		{
			write(1, "KO\n", 3);
			return ;
		}
		i++;
	}
	if (!is_empty(b))
	{
		write(1, "KO\n", 3);
		return ;
	}
	write(1, "OK\n", 3);
}