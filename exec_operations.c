/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:34:15 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/19 15:36:58 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		exec_operations(char *inst)
{
	if (!ft_strncmp(inst, "sa", 3))
		printf("swapping a");
	else if (!ft_strncmp(inst, "sb", 3))
		printf("swapping b");
	else if (!ft_strncmp(inst, "ss", 4))
		printf("swapping a and b");
	else if (!ft_strncmp(inst, "pa", 3))
		printf("push a");
	else if (!ft_strncmp(inst, "pb", 3))
		printf("push b");
	else if (!ft_strncmp(inst, "ra", 3))
		return (0);
	else if (!ft_strncmp(inst, "rb", 3))
		return (0);
	else if (!ft_strncmp(inst, "rr", 3))
		return (0);		
	else if (!ft_strncmp(inst, "rra", 4))
		return (0);
	else if (!ft_strncmp(inst, "rrb", 4))
		return (0);
	else if (!ft_strncmp(inst, "rrr", 4))
		return (0);
	return (-1);
}