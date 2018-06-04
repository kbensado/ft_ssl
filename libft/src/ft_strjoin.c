/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 20:18:13 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 16:06:02 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char			*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		str = ft_strnew(i + j);
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strcat(str, s2);
			return (str);
		}
	}
	return (NULL);
}

char			*ft_strjoin_fs1(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		str = ft_strnew(i + j);
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strcat(str, s2);
			MEMDEL(s1);
			return (str);
		}
	}
	return (NULL);
}

char			*ft_strjoin_fs2(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		str = ft_strnew(i + j);
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strcat(str, s2);
			MEMDEL(s2);
			return (str);
		}
	}
	return (NULL);
}

char			*ft_strjoin_fs3(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		str = ft_strnew(i + j);
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strcat(str, s2);
			MEMDEL(s2);
			MEMDEL(s1);
			return (str);
		}
	}
	return (NULL);
}
