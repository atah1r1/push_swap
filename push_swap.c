/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:50:53 by atahiri           #+#    #+#             */
/*   Updated: 2021/07/14 10:31:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int i;
	(void)b;

	i = - 1;
    printf("\nSTACK A | ");
    while (++i <= a->top)
        printf("%d ", a->items[i]);
    printf("\n");
    printf("STACK B | ");
    i = - 1;
    while (++i <= b->top)
        printf("%d ", b->items[i]);
    printf("\n\n");
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

void	three_numbers(t_stack *a)
{
	int	*sorted;
	int	big_nb;
	int	small_nb;

	sorted = sort_array(a->items, a->top);
	small_nb = sorted[0];
	big_nb = sorted[2];
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



// int		get_median(t_stack *a)
// {
// 	int		median = 0;
// 	int		*sorted;

// 	sorted = sort_array(a->items, a->top);
// 	if (a->maxsize == 5)
// 	{
// 		median = sorted[2];
// 	}
// 	else if (a->maxsize == 4)
// 	{
// 		median = sorted[1];
// 	}
// 	free(sorted);
// 	return (median);
// }

int		find_small_nb(t_stack *a)
{
	int i = -1;
	int b = a->items[0];
	while(++i <= a->top)
	{
		if(a->items[i] < b)
			b = a->items[i];
	} 
	return (b);
}

int find_pos(t_stack *a,int sm)
{
	int i = -1;
	while (++i <= a->top)
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
	if (find < a->top)
	{
		while(find++ < a->top)
			rotate_stack(a, 1, 'a');
	}
	push_b(a, b, 1);
}

void	five_numbers(t_stack *a, t_stack *b)
{
	if (a->top == 4)
	{
		checkandpb(a,b);
		checkandpb(a,b);
		three_numbers(a);
		push_a(a, b, 1);
		push_a(a, b, 1);
	} else {
		checkandpb(a,b);
		three_numbers(a);
		
		push_a(a, b, 1);
		push_a(a, b, 1);
	}
}

void	chunk(t_stack *a, t_stack *b, int start, int end)
{
	(void)b;
	// int	*sorted;
	int i = -1;

	while (++i < a->maxsize)
	{
		if (a->items[i] >= start && a->items[i] <= end)
		{
			push_b(a, b, 1);
		}
	}
	// print_stacks(a, b);
	
}


int	get_element_index(t_stack *stack, int el)
{
	int	i;

	i = -1;
	while (++i < stack->maxsize)
	{
		if (stack->items[i] == el)
			return (i);
	}
	return (0);
}

void	logic(t_stack *a, t_stack *b, int size, int step)
{
	int start;
	int end;
	int *sorted = sort_array(a->items, a->top);

	start = 0;
	end = step - 1;

	if (size <= step)
	{
		chunk(a, b, start, size - 1);
	}
	else 
	{
		// printf("%d\n", size);
		while (start < size)
		{
			chunk(a, b, sorted[start], sorted[end]);
			if (end + step - 1 > size)
			{
				start += step;
				end = size - 1;
				// printf("START ==== %d\n END === %d\n", start, end);
			}
			else 
			{
				start += step;
				end = start + step - 1;
				// printf("START ==== %d\n END === %d\n", start, end);
			}
		}
	}
	// printf("----------\n");
	while (b->top > -1)
	{
		int big_index = get_element_index(b, sorted[b->top]);
		if (big_index < (int)(b->top / 2))
			while (big_index-- >= 0)
				reverse_rotate_stack(b, 1, 'b');
		else
			while (big_index++ < b->top)
				rotate_stack(b, 1, 'b');
		push_a(a, b, 1);
	}
}

void	sorting(t_stack *a, t_stack *b, int argc)
{
	if (argc <= 4)
	{
		if (a->top == 1)
		{
			swapping(a, 1, 'a');
		}
		else
		{
			three_numbers(a);
		}
	}
	else if (argc <= 6)
	{
		five_numbers(a, b);
	}
	else if (argc <= 101)
	{
		logic(a, b, argc - 1, 20);
		// print_stacks(a,b);
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