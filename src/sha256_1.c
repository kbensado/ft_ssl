/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 02:27:34 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/05 02:42:41 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"
#include "../inc/sha.h"

void				sha256_init_washing(t_ssl_sha256 *e)
{
	e->tmp[0] = A;
	e->tmp[1] = B;
	e->tmp[2] = C;
	e->tmp[3] = D;
	e->tmp[4] = E;
	e->tmp[5] = F;
	e->tmp[6] = G;
	e->tmp[7] = H;
	watch_done(e);
}

void				sha256_init(t_ssl_sha256 *e)
{
	e->state[0] = 0x6a09e667;
	e->state[1] = 0xbb67ae85;
	e->state[2] = 0x3c6ef372;
	e->state[3] = 0xa54ff53a;
	e->state[4] = 0x510e527f;
	e->state[5] = 0x9b05688c;
	e->state[6] = 0x1f83d9ab;
	e->state[7] = 0x5be0cd19;
}

void				watch_done_routine(t_ssl_sha256 *e)
{
	A += TA;
	B += TB;
	C += TC;
	D += TD;
	E += TE;
	F += TF;
	G += TG;
	H += TH;
}

void				sha256_washing(t_ssl_sha256 *e)
{
	int				i;
	int				j;

	i = -1;
	j = 0;
	ft_bzero(e->tmp, sizeof(e->tmp));
	ft_bzero(e->b_endian, sizeof(e->b_endian));
	while (++i < 16)
	{
		e->b_endian[i] = (e->buffer[j] << 24) | (e->buffer[j + 1] << 16) |
		(e->buffer[j + 2] << 8) | (e->buffer[j + 3]);
		j += 4;
	}
	while (i < 64)
	{
		e->b_endian[i] = SIG1(e->b_endian[i - 2]) + e->b_endian[i - 7]
		+ SIG0(e->b_endian[i - 15]) + e->b_endian[i - 16];
		i++;
	}
	sha256_init_washing(e);
}

void				sha256_end(t_ssl_sha256 *e)
{
	uint32_t		i;

	i = e->datalen;
	if (e->datalen < 56)
	{
		e->buffer[i++] = 0x80;
		while (i < 56)
			e->buffer[i++] = 0;
	}
	else
	{
		e->buffer[i++] = 0x80;
		while (i < 64)
			e->buffer[i++] = 0;
		sha256_washing(e);
		memset(e->buffer, 0, 56);
	}
	e->bitlen += e->datalen * 8;
	sha256_end_set(e);
}
