/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 21:34:12 by kbensado          #+#    #+#             */
/*   Updated: 2018/06/04 22:54:28 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FILE_H
# define LIBFT_FILE_H

# include <sys/wait.h>
# include <sys/types.h>
# include "./libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>

# define FILE_MAP(x, y) mmap(0, x, PROT_READ, MAP_PRIVATE, y, 0)

typedef struct		s_file
{
	char			*ptr;
	struct stat		file;
	int				fd;
	char			padding[4];

}					t_file;

bool				dir_exist(char *path, DIR *buff);
bool				create_dir(char *path);
int					create_file(char *path, bool del);
t_file				get_file(char *path);
void				rm_file(char *path);
bool				execv_it(int in, bool fd, t_char av);
bool				execve_it(int in, bool fd, char **av, char **env);
char				*real_pwd_file(char *path, char *res, char *tpwd);
char				*trunc_path_file(char *path);
char				*file_already_exist(char *path);
bool				ft_access(char *path);

#endif
