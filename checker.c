/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:22 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/21 15:15:40 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		i;
	t_stack *a;
	t_stack	*b;
	char	*line;
	int		ret;

	i = argc - 1;
	if (!(i))
		ft_error();
	a = n_stack(argc - 1);
	b = n_stack(argc - 1);
	if (check_args(argc, argv))
		ft_error();
	i = argc - 1;
	while (--i >= 0)
		push(a,ft_atoi(argv[i + 1]));
	if (duplicate_element(a))
		ft_error();
	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = ft_gnl(&line);
		if (line[0] == '\0')
			ret = 0;
		else if (instructions_check(line))
			ft_error();
		exec_operations(line, a, b);
		printf("STACK A ---> ");
		i = 0;
		while (i <= a->top)
			printf("%d ", a->items[i++]);
		printf("\nSTACK B ---> ");
		i = 0;
		while (i <= b->top)
			printf("%d ", b->items[i++]);
		printf("\n");
	}

	return 0;
}