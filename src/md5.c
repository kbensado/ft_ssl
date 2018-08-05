/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:49:20 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/05 02:55:51 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"
#include "../inc/md5.h"

void				md5_init(t_ssl_md5 *e)
{
	e->state[0] = 0x67452301;
	e->state[1] = 0xEFCDAB89;
	e->state[2] = 0x98BADCFE;
	e->state[3] = 0x10325476;
}

void				md5_end_set(t_ssl_md5 *e)
{
	int i;

	i = -1;
	e->buffer[56] = e->bitlen[0];
	e->buffer[57] = e->bitlen[0] >> 8;
	e->buffer[58] = e->bitlen[0] >> 16;
	e->buffer[59] = e->bitlen[0] >> 24;
	e->buffer[60] = e->bitlen[1];
	e->buffer[61] = e->bitlen[1] >> 8;
	e->buffer[62] = e->bitlen[1] >> 16;
	e->buffer[63] = e->bitlen[1] >> 24;
	md5_washing(e);
	while (++i < 4)
	{
		e->res[i] = (A >> (i * 8)) & 0x000000ff;
		e->res[i + 4] = (B >> (i * 8)) & 0x000000ff;
		e->res[i + 8] = (C >> (i * 8)) & 0x000000ff;
		e->res[i + 12] = (D >> (i * 8)) & 0x000000ff;
	}
}

void				md5_init_washing(t_ssl_md5 *e)
{
	e->tmp[0] = A;
	e->tmp[1] = B;
	e->tmp[2] = C;
	e->tmp[3] = D;
	first_wash(e);
	second_wash(e);
	third_wash(e);
	final_wash(e);
	A += TA;
	B += TB;
	C += TC;
	D += TD;
}

static void			md5_print_res(t_ssl_wrap *w, t_ssl_file *f,
					t_ssl_md5 *e)
{
	int				j;

	j = -1;
	if (FILE_M == true && REVERSE_M == false)
		ft_printf("MD5 (%s) = ", f->name);
	while (++j < 16)
	{
		ft_printf("%02x", (unsigned char)e->res[j]);
	}
	if (REVERSE_M == true)
		ft_printf(" *%s", f->name);
	WS("");
}

bool				md5_routine(t_ssl_wrap *w, t_ssl_file *f)
{
	t_ssl_md5		e;
	int				i;

	i = -1;
	ft_bzero(&e, sizeof(t_ssl_md5));
	md5_init(&e);
	while (++i < f->len)
	{
		e.buffer[e.datalen] = f->file[i];
		e.datalen++;
		if (e.datalen == 64)
		{
			md5_washing(&e);
			DBL_INT_ADD(e.bitlen[0], e.bitlen[1], 512);
			e.datalen = 0;
		}
	}
	md5_end(&e);
	md5_print_res(w, f, &e);
	return (true);
}
