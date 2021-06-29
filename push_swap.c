/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:53 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/29 18:13:56 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy(int *array, int len)
{
	int	*new_array;
	int	i;

	new_array = malloc(sizeof(int) * (len - 1));
	i = -1;
	while (++i <= len)
		new_array[i] = array[i];
	return (new_array);
}

int	*sort_array(int *array, int len)
{
	int	i;
	int	j;
	int	temp;
	int	*new_array;

	new_array = copy(array, len);
	i = 0;
	while (i <= len)
	{
		j = i + 1;
		while (j <= len)
		{
			if (new_array[i] > new_array[j])
			{
				temp = new_array[i];
				new_array[i] = new_array[j];
				new_array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (new_array);
}

void	three_numbers(t_stack *a)
{
	int	*sorted;
	int	bigger;
	int	smaller;

	sorted = sort_array(a->items, a->top);
	smaller = sorted[0];
	bigger = sorted[2];
	if (a->items[0] == bigger && a->items[1] == smaller)
		swapping(a, 1, 'a');
	else if (a->items[2] == bigger && a->items[1] == smaller)
		rotate_stack(a, 1, 'a');
	else if (a->items[2] == bigger && a->items[0] == smaller)
	{
		swapping(a, 1, 'a');
		reverse_rotate_stack(a, 1, 'a');
	}
	else if (a->items[1] == bigger && a->items[2] == smaller)
	{
		swapping(a, 1, 'a');
		rotate_stack(a, 1, 'a');
	}
	else if (a->items[1] == bigger && a->items[0] == smaller)
	{
		reverse_rotate_stack(a, 1, 'a');
	}
	free(sorted);
}

void	sorting(t_stack *a, t_stack *b, int argc)
{
	(void)b;
	// printf("ARGC ==== %d\n", argc);
	// printf("TOP ==== %d\n", a->top);
	if (argc <= 4)
	{
		if (a->top == 1)
		{
			swapping(a, 1, 'a');
		}
		else 
			three_numbers(a);
	}
}

int     main(int argc, char **argv)
{
	int		i;
	t_stack *a;
	t_stack	*b;

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
	if (is_sorted(a, b))
		return (0);
	// printf("TOP == %d\n", a->top);
	// printf("STACK A ---> ");
	// i = 0;
	// 	while (i <= a->top)
	// 		printf("%d ", a->items[i++]);
	// printf("\nSTACK B ---> ");
	// i = 0;
	// while (i <= b->top)
	// 	printf("%d ", b->items[i++]);
	// printf("\n");
	else
		sorting(a, b, argc);
    return 0;
}