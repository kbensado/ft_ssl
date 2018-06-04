/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 02:25:13 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 19:05:49 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_strsplit_free(t_char *p)
{
	size_t		i;

	i = 0;
	if (0 == p->size)
	{
		return ;
	}
	if (0 == p->array)
	{
		return ;
	}
	else
	{
		while (i < p->size)
		{
			ft_memdel_d((void *)&p->array[i], false, "split_free");
			i++;
		}
		ft_memdel_d((void *)&p->array, false, "split_free");
	}
	p->size = 0;
}

int		free_strsplit(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		MEMDEL(str[i]);
		i++;
	}
	MEMDEL(str);
	return (0);
}
