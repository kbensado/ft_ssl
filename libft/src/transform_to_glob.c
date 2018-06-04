/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_glob.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <joris@gounand.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:00:50 by jgounand          #+#    #+#             */
/*   Updated: 2018/05/23 16:00:59 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*get_content(void *ptr, bool reset)
{
	static void	*content;

	if (reset)
		content = NULL;
	if (!content && ptr)
		content = ptr;
	return (content);
}
