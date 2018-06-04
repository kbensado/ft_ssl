/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:26:04 by kbensado          #+#    #+#             */
/*   Updated: 2018/06/05 01:13:16 by kbensado         ###   ########.fr       */
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

static char	*g_target[5] = {
	"md5",
	"sha256",
	"sha512",
	"des",
	"whirlpool",
	0
};

static int (*g_func_ptr[4]) (t_ssl_wrap *w, t_ssl_file *f) = {
	&hash_md5,
	&hash_sha256,
	&hash_des,
	&hash_whirlpool,
};

bool			get_stdin(t_ssl_wrap *w)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		n;

	n = 0;
	if (STRING_M)
	{
		WS("ft_ssl :Error: '-s' requiered one argument.");
		return (false);
	}
	while ((n = read(0, buffer, BUFF_SIZE)) > 0)
	{
		buffer[n] = 0;
		if (w->file == NULL)
			w->file = ft_strdup(buffer);
		else
			w->file = ft_strjoin_fs1(w->file, buffer);
		ft_bzero(&buffer, BUFF_SIZE + 1);
	}
	ft_printf("out of get_stdin = '%s'\n", w->file);
	return (true);
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
		if (get_stdin(w) == false)
			return (-1);
	if (STRING_M)
		g_func_ptr[t](w, file_wrap(w, &f));
	while (*w->av != NULL)
	{
		g_func_ptr[t](w, file_wrap(w, &f));
	}
	return (1);
}
