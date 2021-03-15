/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:22 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/15 11:53:18 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int i;
	t_stack *a;
	t_stack	*b;
	char instructions[1024];

	i = argc - 1;
	a = n_stack(argc);
	b = n_stack(argc);
	while (--i >= 0)
		push(a, ft_atoi(argv[i + 1]));
	if (!(argc - 1))
		ft_error();
	if (check_args(argc, argv))
		ft_error();
	// if (duplicate_args())
	read(0, instructions, 1024);



	// print stack a
	i = - 1;
    printf("\na | ");
    while (++i <= a->top)
        printf("%d ", a->items[i]);
    printf("\n");
    printf("b | ");
	 
	return 0;
}