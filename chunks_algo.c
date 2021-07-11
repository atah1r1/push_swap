/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:07:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/07/11 11:13:29 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_stack_from_top(t_stack *stack, int start, int end)
{
	int	top_index;

	top_index = stack->top;
	while (top_index-- > -1)
		if (stack->items[top_index] >= start && stack->items[top_index] <= end)
			return (top_index);
	return (-1);
}

int	scan_stack_from_bottom(t_stack *stack, int start, int end)
{
	int	i;

	i = -1;
	while (++i <= stack->top)
		if (stack->items[i] >= start && stack->items[i] <= end)
			return (i);
	return (-1);
}

void	choose_right_operation(t_stack *stack, int top_index, int bottom_index)
{
	if ((stack->top - top_index) < bottom_index)
		while (++top_index <= stack->top)
			rotate_stack(stack, 1, 'a');
	else
		while (bottom_index-- >= 0)
			reverse_rotate_stack(stack, 1, 'a');
}

void	chunk(t_stack *a, t_stack *b, int start, int end)
{
	int	hold_top_index;
	int	hold_bottom_index;
	int	find;

	find = 1;
	while (find)
	{
		find = 0;
		hold_top_index = scan_stack_from_top(a, start, end);
		if (hold_top_index > -1)
			find = 1;
		hold_bottom_index = scan_stack_from_bottom(a, start, end);
		if (hold_bottom_index > -1)
			find = 1;
		choose_right_operation(a, hold_top_index, hold_bottom_index);
		if (find)
			push_b(a, b, 1);
	}
}

void	split_chunks(t_stack *a, t_stack *b, int len, int step)
{
	int	start;
	int	end;
	int	*sorted;

	start = 0;
	end = step - 1;
	sorted = sort_array(a->items, a->maxsize);
	while (start < len)
	{
		chunk(a, b, sorted[start], sorted[end]);
		if (end + step - 1 > len)
		{
			start += step;
			end = len - 1;
		}
		else
		{
			start += step;
			end = start + step - 1;
		}
	}
	free(sorted);
}