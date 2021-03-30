/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:39:22 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/30 18:26:37 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' ||
			str[i] == '\t' ||
			str[i] == '\n' ||
			str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > INT32_MAX || result < INT32_MIN)
		ft_error();
	return (result * sign);
}