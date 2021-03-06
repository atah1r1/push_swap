/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:57:33 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/16 11:57:40 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_memcmp_zero(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	while (i < n && (src[i] != '\0' || dst[i] != '\0'))
	{
		if (src[i] != dst[i])
			return (src[i] - dst[i]);
		i++;
	}
	return (0);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int cc;

	cc = ft_memcmp_zero(s1, s2, n);
	if (cc != 0)
		return (cc);
	else
		return (0);
}