/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:34:41 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/18 02:13:21 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_stack
{
	int			maxsize;
	int			top;
	int			*items;
}				t_stack;


t_stack			*n_stack(int capacity);
int				is_empty(t_stack *stack);
int				is_full(t_stack *stack);
void			push(t_stack *stack, int item);
int 			pop(t_stack *stack);
int				duplicate_element(t_stack *stack);

int			ft_strlen(char *s);
int			ft_error(void);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check_args(int argc, char **argv);
int			instructions_check(char *inst);
char		**ft_split(const char *ss, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_gnl(char **line);
char		*ft_strjoin(char *s, char c);


//
void		applicate_inst(t_stack *a, t_stack *b);
int			exec_operations(char *inst, t_stack *a, t_stack *b);
void		swapping(t_stack *stack);
void		swapping_a_b(t_stack *a, t_stack *b);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		rotate_stack(t_stack *stack);
void		reverse_rotate_stack(t_stack *stack);
void		rr_stack(t_stack *a, t_stack *b);
void		rrr_stack(t_stack *a, t_stack *b);
void		check_stacks(t_stack *a, t_stack *b);

int			is_sorted(t_stack *a, t_stack *b);
//
#endif
