/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 21:32:32 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 00:34:40 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void			ft_lstremove_if_cmp(t_list **begin_list, void (*del)(void *),
				int (*cmp)())
{
	t_list		*list;

	if (*begin_list)
	{
		if (cmp((*begin_list)->content) == 1)
		{
			list = *begin_list;
			*begin_list = (*begin_list)->next;
			del(list);
			free(list);
			list = NULL;
			ft_lstremove_if_cmp(begin_list, del, cmp);
		}
		else
			ft_lstremove_if_cmp(&(*begin_list)->next, del, cmp);
	}
}

void			ft_lstremove_if(t_list **begin_list, void *data_ref,
				int (*cmp)())
{
	t_list		*list;

	if (*begin_list)
	{
		if (!cmp((*begin_list)->content, data_ref))
		{
			list = *begin_list;
			*begin_list = (*begin_list)->next;
			free(list);
			ft_lstremove_if(begin_list, data_ref, cmp);
		}
		else
			ft_lstremove_if(&(*begin_list)->next, data_ref, cmp);
	}
}

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		**tmp;
	t_list		*tmpnext;

	tmp = alst;
	while (*tmp != NULL)
	{
		tmpnext = (*tmp)->next;
		del((*tmp)->content, (*tmp)->content_size);
		free(*tmp);
		*tmp = tmpnext;
	}
}
