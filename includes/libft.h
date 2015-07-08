/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>

size_t	ft_strlen(char *str);
void	*ft_memalloc(size_t size);
char	*ft_strchr(const char *str, int c);
void	ft_strclr(char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
double	ft_matod(char **str);
void	*ft_memcpy(void *str1, const void *str2, size_t n);
void	*ft_bzero(void *s, size_t n);

#endif
