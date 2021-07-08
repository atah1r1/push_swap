/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:34:15 by atahiri           #+#    #+#             */
/*   Updated: 2021/07/08 12:32:28 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		exec_operations(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(inst, "sa", 3))
		swapping(a, 0, 'a');
	else if (!ft_strncmp(inst, "sb", 3))
		swapping(b, 0, 'b');
	else if (!ft_strncmp(inst, "ss", 4))
		swapping_a_b(a, b, 0);
	else if (!ft_strncmp(inst, "pa", 3))
		push_a(a, b, 0);
	else if (!ft_strncmp(inst, "pb", 3))
		push_b(a, b, 0);
	else if (!ft_strncmp(inst, "ra", 3))
		rotate_stack(a, 0, 'a');
	else if (!ft_strncmp(inst, "rb", 3))
		rotate_stack(b, 0, 'b');
	else if (!ft_strncmp(inst, "rr", 3))
		rr_stack(a, b, 0);
	else if (!ft_strncmp(inst, "rra", 4))
		reverse_rotate_stack(a, 0, 'a');
	else if (!ft_strncmp(inst, "rrb", 4))
		reverse_rotate_stack(b, 0, 'b');
	else if (!ft_strncmp(inst, "rrr", 4))
		rrr_stack(a, b, 0);
	return (-1);
}