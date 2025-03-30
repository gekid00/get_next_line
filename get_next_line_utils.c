/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:30:08 by rbourkai          #+#    #+#             */
/*   Updated: 2024/12/04 14:09:34 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	size_t	count;
	size_t	count2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	count = 0;
	while (s1[count])
	{
		result[count] = s1[count];
		count++;
	}
	count2 = 0;
	while (s2[count2])
	{
		result[count] = s2[count2];
		count2++;
		count++;
	}
	return (result[count] = '\0', result);
}

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*memory;
	size_t	size;
	size_t	count;

	if (!src)
		return (NULL);
	size = ft_strlen(src) + 1;
	memory = malloc(size);
	if (!memory)
		return (NULL);
	count = 0;
	while (src[count] != '\0')
	{
		memory[count] = src[count];
		count++;
	}
	memory[count] = '\0';
	return (memory);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (!dest && !src && size > 0)
		return (NULL);
	if (ptr_src > ptr_dest)
	{
		i = 0;
		while (i < size)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		while (size-- > 0)
			ptr_dest[size] = ptr_src[size];
	}
	return (dest);
}
