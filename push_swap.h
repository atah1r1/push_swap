/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:34:41 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/14 15:18:58 by atahiri          ###   ########.fr       */
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


t_stack			*stack(int size);


int			ft_strlen(char *s);
int			ft_error(void);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check_args(int argc, char **argv);
#endif
