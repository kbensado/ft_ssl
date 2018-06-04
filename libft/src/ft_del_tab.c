/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:52:13 by kbensado          #+#    #+#             */
/*   Updated: 2018/03/24 17:58:35 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
**	key is for the case i use a Null terminate or not
*/

void		ft_del_tab(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		MEMDEL(tab[i]);
		i++;
	}
	ft_memdel((void **)&tab);
}
