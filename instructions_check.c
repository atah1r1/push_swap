/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:26:12 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/16 11:54:37 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int         instructions_check(char *inst)
{
    if (!ft_strncmp(inst, "sa", 3))
		return (0);
	else if (!ft_strncmp(inst, "sb", 3))
		return (0);
	else if (!ft_strncmp(inst, "ss", 4))
		return (0);
	else if (!ft_strncmp(inst, "pa", 3))
		return (0);
	else if (!ft_strncmp(inst, "pb", 3))
		return (0);
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