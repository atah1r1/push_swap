/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applicate_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:52:54 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/28 12:49:49 by atahiri          ###   ########.fr       */
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
    int temp[stack->top];
    int top;
    int len;
    int i;

    len = stack->top;
    top = pop(stack);
    i = -1;
    while (!is_empty(stack))
        temp[++i] = pop(stack);
    push(stack, top);
    while (--len >= 0)
        push(stack, temp[len]);
}

void	rr_stack(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	reverse_rotate_stack(t_stack *stack)
{
	int temp;
	int i;
	
	temp = stack->items[stack->top];
	i = stack->maxsize - 1;
	while (i > 0)
	{
		stack->items[i] = stack->items[i - 1];
		i--;
	}
    stack->items[0] = temp;
}

void	rrr_stack(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}