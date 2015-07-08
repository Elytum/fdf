/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void			*ft_bzero(void *s, size_t n)
{
	int			count;
	char		*buffer;

	count = 0;
	buffer = s;
	while (n--)
		buffer[count++] = '\0';
	return (s);
}

void			*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*buffer1;
	const char	*buffer2;

	buffer1 = str1;
	buffer2 = str2;
	while (n--)
		buffer1[n] = buffer2[n];
	return (str1);
}

double			ft_matod(char **str)
{
	char		sign;
	double		value;

	if ((*(*str)) == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if ((*(*str) >= '0' && *(*str) <= '9'))
		sign = 1;
	else if ((*(*str)) == '+')
	{
		sign = 1;
		(*str)++;
	}
	else
		return (0);
	while (*(*str) >= '0' && *(*str) <= '9')
		value = value * 10 + (*(*str)++ - '0');
	while (*(*str) == ' ' || *(*str) == '\t')
		(*str)++;
	return (value * sign);
}

size_t			ft_strlen(char *str)
{
	char		*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

void			*ft_memalloc(size_t size)
{
	char		*memalloc;
	char		*ptr;

	if (!(memalloc = (char*)malloc(sizeof(char) * size)) || !size)
		return (NULL);
	ptr = memalloc;
	while (size--)
		*ptr++ = '\0';
	return ((void*)memalloc);
}
