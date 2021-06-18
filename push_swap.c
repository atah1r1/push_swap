/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:53 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/18 02:31:47 by atahiri          ###   ########.fr       */
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
		swapping(a);
	else if (a->items[2] == bigger && a->items[1] == smaller)
		rotate_stack(a);
	else if (a->items[2] == bigger && a->items[0] == smaller)
	{
		swapping(a);
		reverse_rotate_stack(a);
	}
	else if (a->items[1] == bigger && a->items[2] == smaller)
	{
		swapping(a);
		rotate_stack(a);
	}
	else if (a->items[1] == bigger && a->items[0] == smaller)
		reverse_rotate_stack(a);
	free(sorted);
}

void	sorting(t_stack *a, t_stack *b, int argc)
{
	(void)b;
	if (argc <= 3)
	{
		if (a->top == 1)
		{
			swapping(a);
			write(1, "sa\n", 3);
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
	else
		sorting(a, b, argc);
    return 0;
}