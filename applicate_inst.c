/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applicate_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:52:54 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/19 11:30:45 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapping(t_stack *stack)
{
	int	temp;

	temp = stack->items[stack->top];
	stack->items[stack->top] = stack->items[stack->top - 1];
	stack->items[stack->top - 1] = temp;
}

// void	swapping_b(t_stack *b)
// {
// 	int	temp;

// 	temp = b->items[b->top];
// 	b->items[b->top] = b->items[b->top - 1];
// 	b->items[b->top - 1] = temp;
// }

void	swapping_a_b(t_stack *a, t_stack *b)
{
	swapping(a);
	swapping(b);
}

void	push_a(t_stack *a, t_stack *b)
{
	if (!is_empty(b))
		push(a, b->items[b->top]);
	pop(b);
}

void	push_b(t_stack *a, t_stack *b)
{
	if (!is_empty(a))
		push(b, a->items[a->top]);
	pop(a);
}

void	reverse_rotate_a(t_stack *a)
{
	int		temp;
	int		i;

	temp = a->items[a->top - 1];
	i = a->top - 1;
	while (i > 0)
	{
		a->items[i] = a->items[i - 1];
		i--;
	}
	a->items[0] = temp;
}

void	applicate_inst(t_stack *a, t_stack *b)
{
	// logic here !!
	// reverse_rotate_a(a);
	// swapping(a);
}