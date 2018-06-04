/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:02:57 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 16:24:25 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char			*ft_replace_nonprint(char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 1 && s[i] <= 31)
			s[i] = 0;
		i++;
	}
	return (s);
}

char			*ft_strdel_char(char *s, char c)
{
	size_t		i;
	size_t		j;
	char		*buff;

	i = 0;
	j = 0;
	buff = ft_strdup(s);
	ft_bzero(s, ft_strlen(s));
	while (buff[i])
	{
		if (buff[i] != c)
		{
			s[j] = buff[i];
			j++;
		}
		i++;
	}
	s[j] = 0;
	MEMDEL(buff);
	return (s);
}

char			*ft_str_replace(char *s, char c, char t)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			s[i] = t;
		i++;
	}
	return (s);
}

char			*ft_strchr(char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char			*ft_strchr_b(char *s, int c)
{
	int		size;

	size = ft_strlen(s) - 1;
	while (size)
	{
		if (s[size] == (char)c)
			return (&s[size]);
		size--;
	}
	if (s[size] == (char)c)
		return (&s[size]);
	return (NULL);
}
