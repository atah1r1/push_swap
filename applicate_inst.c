/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applicate_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:52:54 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/29 18:07:44 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapping(t_stack *stack, int print, char stack_type)
{
	int	temp;

	if (!is_empty(stack))
	{
		temp = stack->items[stack->top];
		stack->items[stack->top] = stack->items[stack->top - 1];
		stack->items[stack->top - 1] = temp;
	}
	if (print == 1 && stack_type == 'a')
		printf("sa\n");
	if (print == 1 && stack_type == 'b')
		printf("sb\n");
}

void	swapping_a_b(t_stack *a, t_stack *b, int print)
{
	swapping(a, 0, 'a');
	swapping(b, 0, 'b');
	if (print == 1)
		printf("ss\n");
}

void	push_a(t_stack *a, t_stack *b, int print)
{
	if (!is_empty(b))
		push(a, b->items[b->top]);
	pop(b);
	if (print == 1)
		printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b, int print)
{
	if (!is_empty(a))
		push(b, a->items[a->top]);
	pop(a);
	if (print == 1)
		printf("pb\n");
}

void	rotate_stack(t_stack *stack, int print, char stack_type)
{
	int	temp[stack->top];
	int	top;
	int	len;
	int	i;

    len = stack->top;
    top = pop(stack);
    i = -1;
    while (!is_empty(stack))
        temp[++i] = pop(stack);
    push(stack, top);
    while (--len >= 0)
        push(stack, temp[len]);
	if (print == 1 && stack_type == 'a')
		printf("ra\n");
	if (print == 1 && stack_type == 'b')
		printf("rb\n");
}

void	rr_stack(t_stack *a, t_stack *b, int print)
{
	rotate_stack(a, 0, 'a');
	rotate_stack(b, 0, 'b');
	if (print == 1)
		printf("rr\n");
}

void	reverse_rotate_stack(t_stack *stack, int print, char stack_type)
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
	if (print == 1 && stack_type == 'a')
		printf("rra\n");
	if (print == 1 && stack_type == 'b')
		printf("rrb\n");
}

void	rrr_stack(t_stack *a, t_stack *b, int print)
{
	reverse_rotate_stack(a, 0, 'a');
	reverse_rotate_stack(b, 0, 'b');
	if (print == 1)
		printf("rrr\n");
}