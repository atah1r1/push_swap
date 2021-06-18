/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 02:12:50 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/18 02:13:01 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	int	i;

	if (!is_empty(b))
		return (0);
	i = -1;
	while (++i <= a->top - 1)
	{
		if (a->items[i] < a->items[i + 1])
			return (0);
	}
	return (1);
}