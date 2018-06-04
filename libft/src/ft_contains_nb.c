/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <joris@gounand.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:22:30 by jgounand          #+#    #+#             */
/*   Updated: 2018/05/23 16:22:45 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t		ft_contains_nb(char *str, char target)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (target == str[i])
			res++;
		i++;
	}
	return (res);
}
