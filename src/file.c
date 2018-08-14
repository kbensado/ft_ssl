/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 22:39:34 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/14 10:59:03 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

t_ssl_file		*file_wrap(t_ssl_wrap *w, t_ssl_file *f)
{
	t_file		tmp;

	if (STDIN_M || PRINT_M)
	{
		f->file = get_stdin(w);
		f->len = (long long)ft_strlen(f->file);
		STDIN_M = false;
		return (f);
	}
	if (STRING_M)
	{
		f->file = ft_strdup(*w->av);
		f->len = (long long)ft_strlen(*w->av);
		w->av++;
		return (f);
	}
	tmp = get_file(*w->av);
	if (tmp.fd == -1)
	{
		ft_printf("ft_ssl :%s: '%s' ", w->hash, *w->av);
		perror("");
		f->len = 0;
		w->av++;
		return (f);
	}
	if (tmp.fd > -1)
		FILE_M = true;
	f->name = *w->av;
	f->file = tmp.ptr;
	f->len = tmp.file.st_size;
	w->av++;
	return (f);
}
