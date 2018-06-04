/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_macro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 20:46:18 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/22 00:38:19 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/libft_file.h"

/*
** "in" le fd dans lequel rediriger le fork (see bool fd)
*/

bool		execv_it(int in, bool fd, t_char av)
{
	pid_t	daddy;
	int		status;

	daddy = fork();
	if (daddy > 0)
		wait4(daddy, &status, 0, 0);
	else if (daddy == 0)
	{
		if (fd == true)
			dup2(in, 1);
		execv(av.array[0], av.array);
	}
	if (av.array)
		ft_del_tab(av.array, av.size);
	return (true);
}

bool		execve_it(int in, bool fd, char **av, char **env)
{
	pid_t	daddy;
	int		status;
	size_t	i;

	i = 0;
	daddy = fork();
	(void)env;
	if (daddy > 0)
		wait4(daddy, &status, 0, 0);
	else if (daddy == 0)
	{
		if (fd == true)
			dup2(in, 1);
		execve(av[0], av, env);
	}
	while (av[i])
		i++;
	ft_del_tab(av, i);
	return (true);
}
