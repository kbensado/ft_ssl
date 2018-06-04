/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:05:43 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 16:14:35 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft_malloc.h"

void		*ft_realloc(void *ptr, size_t size, size_t old_size)
{
	unsigned char	*res;
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char *)ptr;
	if (ptr == NULL)
		return (ft_memalloc(size));
	res = ft_memalloc(size);
	while (i < old_size)
	{
		res[i] = buf[i];
		i++;
	}
	if (ptr != NULL)
		ft_memdel((void *)&ptr);
	return ((void *)res);
}
