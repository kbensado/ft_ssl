/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 12:52:44 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 16:20:24 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_memdel_ultimate(size_t count, ...)
{
	va_list		ap;
	void		*res;

	res = NULL;
	va_start(ap, count);
	while (count)
	{
		res = va_arg(ap, void *);
		ft_memdel(&res);
		count--;
	}
}

void	ft_memdel_d(void **ap, bool print, char *debug)
{
	if (print == true)
		ft_printf("memdel entry : '%s' : '%p'\n", debug, *ap);
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_memdel(void **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
