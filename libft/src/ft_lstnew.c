/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 21:31:55 by kbensado          #+#    #+#             */
/*   Updated: 2018/03/25 16:04:00 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_lstforeach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list;

	list = begin_list;
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}

void		ft_lstforeach_if(t_list *begin_list, void (*f)(void *),
			void *data_ref, int (*cmp)())
{
	t_list	*list;

	list = begin_list;
	while (list)
	{
		if (cmp(list->content, data_ref) == 0)
			f(list->content);
		list = list->next;
	}
}

void		ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *begin_list;

	begin_list = *begin_list1;
	if (begin_list == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (begin_list->next)
		begin_list = begin_list->next;
	begin_list->next = begin_list2;
}

t_list		*ft_lstnew(void *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (content == NULL)
	{
		list->content_size = 0;
		list->content = NULL;
	}
	else
	{
		list->content_size = content_size;
		list->content = ft_memalloc_d(content_size, false, "lstnew");
		if (!list->content)
			return (NULL);
		ft_memcpy(list->content, content, content_size);
	}
	list->next = NULL;
	return (list);
}
