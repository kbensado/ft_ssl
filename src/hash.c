/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 20:39:21 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/14 11:39:37 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"
#include "../inc/md5.h"

int			hash_md5(t_ssl_wrap *w, t_ssl_file *f)
{
	if (f == NULL)
		return (-1);
	if (f->len != 0)
		md5_routine(w, f);
	while (*w->av != NULL)
	{
		file_wrap(w, f);
		if (f->len != 0)
			md5_routine(w, f);
	}
	munmap(f->file, f->len);
	STRING_M = false;
	PRINT_M = false;
	FILE_M = false;
	return (1);
}

int			hash_sha256(t_ssl_wrap *w, t_ssl_file *f)
{
	if (f == NULL)
		return (-1);
	sha256_routine(w, f);
	while (*w->av != NULL)
	{
		WS(*w->av);
		w->av++;
		sha256_routine(w, f);
	}
	return (1);
}

int			hash_sha512(t_ssl_wrap *w, t_ssl_file *f)
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

int			hash_des(t_ssl_wrap *w, t_ssl_file *f)
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
