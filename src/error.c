/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:07:05 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/14 11:40:34 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

void		error_fd_handle(t_ssl_wrap *w, t_ssl_file *f)
{
	ft_printf("ft_ssl :%s: '%s' ", w->hash, *w->av);
	perror("");
	f->len = 0;
	w->av++;
}

int			ft_usage(char *str)
{
	WS(str);
	return (1);
}
