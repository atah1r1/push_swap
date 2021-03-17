/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applicate_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:52:54 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/17 18:03:01 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapping_a(t_stack *a)
{
	int	temp;

	temp = a->items[a->top];
	a->items[a->top] = a->items[a->top - 1];
	a->items[a->top - 1] = temp;
}

void	swapping_b(t_stack *b)
{
	int	temp;

	temp = b->items[b->top];
	b->items[b->top] = b->items[b->top - 1];
	b->items[b->top - 1] = temp;
}

void	swapping_a_b(t_stack *a, t_stack *b)
{
	swapping_a(a);
	swapping_b(b);
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, b->items[b->top]);
}

void	applicate_inst(t_stack *a, t_stack *b)
{
	// logic here !!
	push_a(a, b);
}