/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 12:50:27 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 16:16:29 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

void		*ft_memalloc_d(size_t size, bool print, char *debug)
{
	void	*mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
	{
		WS("Malloc error");
		exit(42);
		return (NULL);
	}
	if (print == true)
		ft_printf("malloc entry : '%s' : '%p' : '%zu'\n", debug, mem, size);
	ft_bzero(mem, size);
	return (mem);
}

void		*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
	{
		WS("Malloc error");
		exit(42);
		return (NULL);
	}
	ft_bzero(mem, size);
	return (mem);
}
