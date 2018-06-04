/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 12:19:18 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 16:12:33 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_char		ft_duplicate_tchar(t_char *target)
{
	t_char		res;
	size_t		i;

	i = 0;
	ft_bzero(&res, sizeof(t_char));
	res.array = ft_memalloc_d(sizeof(char *) * target->size, false,
			"duplicate_t_char");
	while (i < target->size)
	{
		res.array[i] = ft_strdup(target->array[i]);
		i++;
	}
	res.size = i;
	return (res);
}

char		*ft_strndup(char *s1, size_t n)
{
	size_t	i;
	size_t	len;
	char	*dst;

	i = 0;
	len = 0;
	dst = NULL;
	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (len > n)
		len = n;
	dst = ft_strnew(len);
	ft_bzero(dst, len);
	while (i < len && n)
	{
		dst[i] = s1[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(char *s1)
{
	size_t	i;
	size_t	len;
	char	*dst;

	i = 0;
	len = 0;
	dst = NULL;
	if (s1 == NULL)
		return (NULL);
	while (s1[len])
		len++;
	dst = ft_memalloc_d(len + 1, false, "dup");
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	return (dst);
}
