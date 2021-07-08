/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:53 by atahiri           #+#    #+#             */
/*   Updated: 2021/07/08 14:13:23 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int i;
	(void)b;

	i = a->top;
	printf("STACK A ---> ");
	while (i > -1)
		printf("%d ", a->items[i--]);
	printf("\nSTACK B ---> ");
	i = b->top;
	while (i > -1)
		printf("%d ", b->items[i--]);
	printf("\n");
}

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

void	three_numbers(t_stack *a, t_stack *b)
{
	int	*sorted;
	int	big_nb;
	int	small_nb;
	(void)b;

	sorted = sort_array(a->items, a->top);
	small_nb = sorted[0];
	big_nb = sorted[2];
	// printf("iterm0 == %d\n item1 == %d\n", a->items[0], a->items[1]);
	if (a->items[2] == big_nb && a->items[1] == small_nb)
	{
		rotate_stack(a, 1, 'a');
	}
	else if (a->items[1] == big_nb && a->items[2] == small_nb)
	{
		swapping(a, 1, 'a');
		rotate_stack(a, 1, 'a');
	}
	else if (a->items[2] == big_nb && a->items[0] == small_nb)
	{
		rotate_stack(a, 1, 'a');
		swapping(a, 1, 'a');
	}
	else if (a->items[1] == big_nb && a->items[0] == small_nb)
	{
		reverse_rotate_stack(a, 1, 'a');
	}
	else if (a->items[0] == big_nb && a->items[1] == small_nb)
	{
		swapping(a, 1, 'a');
	}
	free(sorted);
}



int		get_median(t_stack *a)
{
	int		median = 0;
	int		*sorted;

	sorted = sort_array(a->items, a->top);
	if (a->maxsize == 5)
	{
		median = sorted[2];
	}
	else if (a->maxsize == 4)
	{
		median = sorted[1];
	}
	free(sorted);
	return (median);
}

int		find_small_nb(t_stack *a)
{
	int i = -1;
	int b = a->items[0];
	while(++i < a->maxsize)
	{
		if(a->items[i] <= b)
			b = a->items[i];
	} 
	return (b);
}

int find_pos(t_stack *a,int sm)
{
	int i = -1;
	while (++i < a->maxsize)
	{
		if (a->items[i] == sm)
			return (i);
	}
	return (-1);
}

void	checkandpb(t_stack *a,t_stack *b)
{
	int small_nb = find_small_nb(a);
	int find = find_pos(a,small_nb);
	printf("%d\n", find);
	printf("TOP == %d\n", a->top);
	// sleep(5);
	if (find > 2)
	{
		while(find != a->top)
		{
			rotate_stack(a, 1, 'a');
			find--;
		}
	}
	else
	{
		while(find != a->top)
		{
			reverse_rotate_stack(a, 1, 'a');
			find--;
			if (find == -2)
				find = a->top;
		}	
	}
	push_b(a, b, 1);
	// print_stacks(a, b);
}

void	five_numbers(t_stack *a, t_stack *b)
{
	// int	median;
	// int	i;
	(void)b;

	checkandpb(a,b);
	checkandpb(a,b);
	
	// i = -1;
	
	// printf("%d\n", find);
	// median = get_median(a);
	// printf("TOP === %d\n", a->items[a->top]);
	// printf("MEDIANE === %d\n", median);
	// while (++i < a->maxsize)
	// {
	// 	if (a->items[a->top] < median)
	// 	{
	// 		printf("TOP == %d\n", a->items[a->top]);
	// 		push_b(a, b, 1);
	// 	}
	// 	else
	// 		rotate_stack(a, 1, 'a');
	// }
	print_stacks(a, b);
	// three_numbers(a, b);
	// if (b->top == 0)
	// 	push_a(a, b, 1);
	// else
	// {
		// if (b->items[b->top] < b->items[b->top - 1])
		// {
		// 	swapping(b, 1, 'b');
		// }
		// push_a(a, b, 1);
		// push_a(a, b, 1);
	// }
	// print_stacks(a, b);
	// print_stacks(a, b);
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
		{
			three_numbers(a, b);
			// print_stacks(a, b);
		}
	}
	else
	{
		five_numbers(a, b);
		// print_stacks(a, b);
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
	{
		sorting(a, b, argc);
		// print_stacks(a, b);
	}
		
    return 0;
}