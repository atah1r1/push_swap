/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:22 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/14 15:51:28 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>

int		main(int argc, char **argv)
{
	int i;
	char instructions[1024];

	i = 0;
	if (!(argc - 1))
		ft_error();
	if (check_args(argc, argv))
		ft_error();
	read(0, instructions, 1024);
	printf("%s", instructions);
	return 0;
}