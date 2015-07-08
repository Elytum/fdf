/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char				*ft_strdup(const char *str)
{
	char			*str_copy;
	int				size;
	int				count;

	str_copy = NULL;
	count = 0;
	size = (int)ft_strlen((char *)str);
	str_copy = malloc (size * sizeof(char) + 1);
	if (str_copy == NULL)
		return (NULL);
	while (count != size)
	{
		str_copy[count] = str[count];
		count++;
	}
	str_copy[count] = '\0';
	return (str_copy);
}

char				*ft_strcat(char *dest, const char *src)
{
	ft_strcpy(&dest[ft_strlen(dest)], src);
	return (dest);
}
