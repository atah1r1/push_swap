/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applicate_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:52:54 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/27 14:33:16 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapping(t_stack *stack)
{
	int	temp;
	if (!is_empty(stack))
	{
		temp = stack->items[stack->top];
		stack->items[stack->top] = stack->items[stack->top - 1];
		stack->items[stack->top - 1] = temp;
	}
}

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

void rotate_stack(t_stack *stack)
{
    int i;
    int tmp[stack->top];
    int top;
    int len;

    len = stack->top;
    top = pop(stack);
    i = -1;
    while (!is_empty(stack))
        tmp[++i] = pop(stack);
    push(stack, top);
    while (--len >= 0)
        push(stack, tmp[len]);
}

void	applicate_inst(t_stack *a, t_stack *b)
{
	// logic here !!
	// reverse_rotate_a(a);
	// swapping(a);
}