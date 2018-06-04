/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:54:08 by kbensado          #+#    #+#             */
/*   Updated: 2018/05/23 16:12:00 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

t_char		*ft_getenv(char **env, bool equ)
{
	t_char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(res = ft_memalloc(sizeof(t_char))))
		exit(-1);
	while (env[i])
		i++;
	res->array = ft_memalloc(sizeof(char *) * i);
	res->size = i;
	i = 0;
	while (env[i])
	{
		while ((equ == true) && (env[i][j] && env[i][j] != '='))
			j++;
		res->array[i] = ft_strdup(env[i] + (j + equ));
		i++;
		j = 0;
	}
	return (res);
}

char		*ft_getfromenv(t_char *env, char *name)
{
	size_t	i;
	char	*tmp;

	if (!env || !name)
		return (NULL);
	i = 0;
	while (i < env->size)
	{
		tmp = NULL;
		if ((tmp = ft_strchr(env->array[i], '=')))
			*tmp = '\0';
		if (!ft_strcmp(env->array[i], name))
		{
			*tmp = '=';
			return (tmp + 1);
		}
		if (tmp)
			*tmp = '=';
		i++;
	}
	return (NULL);
}
