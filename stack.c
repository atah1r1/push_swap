/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:36:35 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/15 11:56:02 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *n_stack(int  capacity)
{
    t_stack *stack;

    stack = (t_stack*)malloc(sizeof(t_stack));
    stack->maxsize = capacity;
    stack->top = -1;
    stack->items = malloc(sizeof(int) * capacity);
    return (stack);
}

int     is_empty(t_stack *stack)
{
    return (stack->top == -1);
}

int     is_full(t_stack *stack)
{
    return (stack->top == stack->maxsize - 1);
}

void    push(t_stack *stack, int item)
{
    if (!(is_full(stack)))
    {
        stack->items[++stack->top] = item;
    }
}

int    pop(t_stack *stack)
{
    if (!(is_empty(stack)))
    {
        return stack->items[stack->top--];
    }
    return -1;
}