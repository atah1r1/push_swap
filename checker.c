/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:22 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/18 10:05:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int i;
	t_stack *a;
	t_stack	*b;
	char	**parts;
	char instructions[1024];

	i = argc - 1;
	a = n_stack(argc);
	b = n_stack(argc);
	while (--i >= 0)
		push(a, ft_atoi(argv[i + 1]));
	if (duplicate_element(a))
		ft_error();
	if (!(argc - 1))
		ft_error();
	if (check_args(argc, argv))
		ft_error();
	read(0, instructions, 1024);
	parts = ft_split(instructions, '\n');
	int j = 0;
	while (parts[j] != '\0')
	{
		if (instructions_check(parts[j]))
			ft_error();
		else
			applicate_inst(a, b);
		j++;
	}



	// print stack a
	i = -1;
	while (++i <= a->top)
		printf("%d\n", a->items[i]);
	printf("--\na\n");
	// printf("\n");
	// print stack b
	printf("************************\n");
	i = -1;
	while (++i <= b->top)
		printf("%d\n", b->items[i]);
	printf("--\nb\n");



	return 0;
}