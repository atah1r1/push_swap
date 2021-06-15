/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:22 by atahiri           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/15 01:03:59 by atahiri          ###   ########.fr       */
=======
/*   Updated: 2021/03/31 13:41:41 by atahiri          ###   ########.fr       */
>>>>>>> 62c2c398a1328c4141c9b5d688f29e8660bd1b5c
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
	if (argc == 1)
		return 0;
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
	while (ret > 0 || argc == 1)
	{
		ret = ft_gnl(&line);
		if (line[0] == '\0')
			ret = 0;
		else if (instructions_check(line))
			ft_error();
		exec_operations(line, a, b);
		//--------------------------------------
		printf("STACK A ---> ");
		i = 0;
		while (i <= a->top)
			printf("%d ", a->items[i++]);
		printf("\nSTACK B ---> ");
		i = 0;
		while (i <= b->top)
			printf("%d ", b->items[i++]);
		printf("\n");
		//--------------------------------------
		// printf("%d\n", a->items[a->maxsize - a->top - 1]);
	}
	check_stacks(a, b);
	return 0;
}