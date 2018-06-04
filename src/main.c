/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:04:01 by kbensado          #+#    #+#             */
/*   Updated: 2018/06/05 01:12:44 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int					wrap_state(t_ssl_wrap *w)
{
	int				ret;

	ret = 0;
	if (*w->av == NULL)
		return (0);
	if ((ret = cmd_wrapper(w)) < 0)
		return (-1);
	return (1);
}

int					main(int ac, char **av)
{
	t_ssl_wrap		w;

	ft_bzero(&w, sizeof(w));
	w.av = ++av;
	if (ac == 1)
		return (ft_usage(USAGE));
	w.ret = wrap_state(&w);
	return (w.ret);
}
