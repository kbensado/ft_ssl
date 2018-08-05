/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 02:49:43 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/05 02:56:09 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"
#include "../inc/md5.h"

void				md5_washing(t_ssl_md5 *e)
{
	int				i;
	int				j;

	i = -1;
	j = 0;
	ft_bzero(e->tmp, sizeof(e->tmp));
	ft_bzero(e->b_endian, sizeof(e->b_endian));
	while (++i < 16)
	{
		e->b_endian[i] = (e->buffer[j]) + (e->buffer[j + 1] << 8) +
		(e->buffer[j + 2] << 16) + (e->buffer[j + 3] << 24);
		j += 4;
	}
	md5_init_washing(e);
}

void				md5_end(t_ssl_md5 *e)
{
	uint32_t		i;

	i = e->datalen;
	if (e->datalen < 56)
	{
		e->buffer[i++] = 0x80;
		while (i < 56)
			e->buffer[i++] = 0;
	}
	else if (e->datalen >= 56)
	{
		e->buffer[i++] = 0x80;
		while (i < 64)
			e->buffer[i++] = 0x80;
		md5_washing(e);
		memset(e->buffer, 0, 56);
	}
	DBL_INT_ADD(e->bitlen[0], e->bitlen[1], 8 * e->datalen);
	md5_end_set(e);
}
