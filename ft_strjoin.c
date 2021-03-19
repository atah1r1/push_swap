/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:15:03 by atahiri           #+#    #+#             */
/*   Updated: 2021/03/19 12:21:20 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	count;

	dest_length = 0;
	while (dest[dest_length] != '\0' && dest_length < size)
		dest_length++;
	count = dest_length;
	src_length = 0;
	while (src[src_length] != '\0')
		src_length++;
	while (count + 1 < size && ((char *)src)[count - dest_length] != '\0')
	{
		dest[count] = ((char *)src)[count - dest_length];
		count++;
	}
	if (dest_length < size)
		dest[count] = '\0';
	return (dest_length + src_length);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	length_src;
	int		i;

	if (!dest || !src)
		return (0);
	length_src = 0;
	while (src[length_src])
		length_src++;
	if (n != 0)
	{
		i = -1;
		if (length_src + 1 < n)
		{
			while (++i < (int)length_src)
				dest[i] = src[i];
		}
		else
		{
			while (++i < (int)n - 1)
				dest[i] = src[i];
		}
		dest[i] = '\0';
	}
	return (length_src);
}

char	*ft_strjoin(char *s1, char *s2, int free_s1, int free_s2)
{
	size_t	size;
	int		s1_length;
	int		s2_length;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	s1_length = -1;
	while (s1[++s1_length])
		size++;
	s2_length = -1;
	while (s2[++s2_length])
		size++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1_length + 1);
	ft_strlcat(ptr, s2, size + 1);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (ptr);
}