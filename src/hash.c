/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 20:39:21 by kbensado          #+#    #+#             */
/*   Updated: 2018/06/04 23:24:00 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int			hash_md5(t_ssl_wrap *w, t_ssl_file *f)
{
	if (f == NULL)
		return (-1);
	ft_printf("len = %d for file = \n'%s'\n", f->len, f->file);
	while (*w->av != NULL)
	{
		WS(*w->av);
		w->av++;
	}
	return (0);
}

int			hash_sha256(t_ssl_wrap *w, t_ssl_file *f)
{
	if (f == NULL)
		return (-1);
	while (*w->av != NULL)
	{
		WS(*w->av);
		w->av++;
	}
	return (0);
}

int			hash_des(t_ssl_wrap *w, t_ssl_file *f)
{
	if (f == NULL)
		return (-1);
	while (*w->av != NULL)
	{
		WS(*w->av);
		w->av++;
	}
	return (0);
}

int			hash_whirlpool(t_ssl_wrap *w, t_ssl_file *f)
{
	if (f == NULL)
		return (-1);
	while (*w->av != NULL)
	{
		WS(*w->av);
		w->av++;
	}
	return (1);
}
