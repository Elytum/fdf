/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char				*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	if (*str == c)
		return ((char*)str);
	return (NULL);
}

void				ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
			*(s++) = '\0';
	}
}

char				*ft_strcpy(char *dest, const char *src)
{
	char			*destination;

	destination = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (destination);
}

static inline char	*null(char *s)
{
	char			*str;

	str = ft_memalloc(ft_strlen(s) + 1);
	ft_strcpy(str, s);
	return (str);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;

	if (!s1 && s2)
		return (null((char*)s2));
	else if (!s2 && s1)
		return (null((char*)s1));
	else if (s1 && s2)
	{
		str = ft_memalloc(ft_strlen((char *)s1) +
						ft_strlen((char *)s2) + 1);
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
