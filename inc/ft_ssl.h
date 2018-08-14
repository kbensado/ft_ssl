/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:04:07 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/09 20:52:04 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/inc/libft.h"

# define BUFF_SIZE 4096
# define REVERSE_M w->flag[0]
# define PRINT_M w->flag[1]
# define QUIET_M w->flag[2]
# define STRING_M w->flag[3]
# define FILE_M w->flag[4]
# define STDIN_M w->flag[5]
# define USAGE "usage: ft_ssl command [command opts] [command args]"

typedef struct	s_ssl_file
{
	char		*file;
	char		*name;
	long long	len;

}				t_ssl_file;

typedef struct	s_ssl_wrap
{
	char		**av;
	char		*file;
	char		*hash;
	int			ret;
	bool		flag[6];

}				t_ssl_wrap;

/*
** main.c
*/

int				wrap_state(t_ssl_wrap *w);

/*
** command.c
*/

char			*get_stdin(t_ssl_wrap *w);
void			get_flag(t_ssl_wrap *w);
int				cmd_wrapper(t_ssl_wrap *w);
int				is_cmd(t_ssl_wrap *w);

/*
** file.c
*/

t_ssl_file		*file_wrap(t_ssl_wrap *w, t_ssl_file *f);

/*
** hash.c
*/

int				hash_md5(t_ssl_wrap *w, t_ssl_file *f);
bool			md5_routine(t_ssl_wrap *w, t_ssl_file *f);
bool			sha256_routine(t_ssl_wrap *w, t_ssl_file *f);
int				hash_sha256(t_ssl_wrap *w, t_ssl_file *f);
int				hash_sha512(t_ssl_wrap *w, t_ssl_file *f);
int				hash_des(t_ssl_wrap *w, t_ssl_file *f);
int				hash_whirlpool(t_ssl_wrap *w, t_ssl_file *f);

/*
** error.c
*/

int				ft_usage(char *str);

#endif
