/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acces.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <joris@gounand.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:23:07 by jgounand          #+#    #+#             */
/*   Updated: 2018/05/23 16:23:50 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	acces_file(const char *path, int type, int permission)
{
	struct stat	sb;

	if (stat(path, &sb) < 0)
		return (-1);
	if ((sb.st_mode & S_IFMT) != (unsigned int)type)
		return (-1);
	if ((sb.st_mode & permission) == 0)
		return (-1);
	return (0);
}
