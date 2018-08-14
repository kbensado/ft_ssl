/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:26:04 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/14 09:41:19 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

static char *g_flag[5] = {
	"-r",
	"-p",
	"-q",
	"-s",
	0
};

static char	*g_target[6] = {
	"md5",
	"sha256",
	"sha512",
	"des",
	"whirlpool",
	0
};

static int (*g_func_ptr[5]) (t_ssl_wrap *w, t_ssl_file *f) = {
	&hash_md5,
	&hash_sha256,
	&hash_sha512,
	&hash_des,
	&hash_whirlpool,
};

char			*get_stdin(t_ssl_wrap *w)
{
	char		buffer[BUFF_SIZE + 1];
	char		*res;
	ssize_t		n;

	n = 0;
	res = NULL;
	if (STRING_M && *w->av == NULL)
	{
		WS("ft_ssl :Error: '-s' requiered one argument.");
		return (NULL);
	}
	while ((n = read(0, buffer, BUFF_SIZE)) > 0)
	{
		buffer[n] = 0;
		if (res == NULL)
			res = ft_strdup(buffer);
		else
			res = ft_strjoin_fs1(res, buffer);
		ft_bzero(&buffer, BUFF_SIZE + 1);
	}
	return (res);
}

/*
**	catch flags and iterate argv
*/

void			get_flag(t_ssl_wrap *w)
{
	int			i;

	i = -1;
	if (*w->av == NULL)
		return ;
	while (g_flag[++i] != NULL)
	{
		if (ft_strcmp(g_flag[i], *w->av) == 0)
		{
			w->flag[i] = true;
			w->av++;
			break ;
		}
	}
	if (i == 3)
		return ;
	if (i != 4)
		get_flag(w);
}

/*
**	catch the cmd, do not iterate argv
*/

int				is_cmd(t_ssl_wrap *w)
{
	int			i;

	i = -1;
	while (g_target[++i] != NULL)
	{
		if (ft_strcmp(g_target[i], *w->av) == 0)
			return (i);
	}
	ft_printf("ft_ssl :Error: '%s' is an invalid command.\n", *w->av);
	return (-1);
}

/*
**	setting up before to compute the hash,
**  catch g_flag or trigger stdin in case of no argv
*/

int				cmd_wrapper(t_ssl_wrap *w)
{
	int			t;
	t_ssl_file	f;

	t = is_cmd(w);
	w->av++;
	if (t == -1)
		return (-1);
	w->hash = ft_strdup(g_target[t]);
	get_flag(w);
	if (*w->av == NULL)
	{
		STDIN_M = true;
		g_func_ptr[t](w, file_wrap(w, &f));	
	}
	while (*w->av != NULL)
		g_func_ptr[t](w, file_wrap(w, &f));
	return (1);
}
