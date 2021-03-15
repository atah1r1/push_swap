/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:22:51 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/15 14:29:50 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		duplicate_element(t_stack *stack)
{
    int	i;
    int	j;
    int	count;

    i = -1;
    while (++i < stack->maxsize)
    {
	    j = -1;
	    count = 0;
	    while (++j < stack->maxsize)
	    {
			if (stack->items[i] == stack->items[j])
				count++;
	    }
	    if (count > 1)
			return 1;
    }
    return 0;
}