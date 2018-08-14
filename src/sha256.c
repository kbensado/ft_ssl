/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 00:06:54 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/14 11:42:44 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"
#include "../inc/sha.h"

static const unsigned int g_c[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void				watch_done(t_ssl_sha256 *e)
{
	int				i;
	unsigned int	tmp[2];

	i = -1;
	bzero(tmp, sizeof(tmp));
	while (++i < 64)
	{
		tmp[0] = TH + EP1(TE) + CH(TE, TF, TG) + g_c[i] + e->b_endian[i];
		tmp[1] = EP0(TA) + MAJ(TA, TB, TC);
		TH = TG;
		TG = TF;
		TF = TE;
		TE = TD + tmp[0];
		TD = TC;
		TC = TB;
		TB = TA;
		TA = tmp[0] + tmp[1];
	}
	watch_done_routine(e);
}

void				sha256_end_set(t_ssl_sha256 *e)
{
	int				i;

	i = -1;
	e->buffer[63] = e->bitlen;
	e->buffer[62] = e->bitlen >> 8;
	e->buffer[61] = e->bitlen >> 16;
	e->buffer[60] = e->bitlen >> 24;
	e->buffer[59] = e->bitlen >> 32;
	e->buffer[58] = e->bitlen >> 40;
	e->buffer[57] = e->bitlen >> 48;
	e->buffer[56] = e->bitlen >> 56;
	sha256_washing(e);
	while (++i < 4)
	{
		e->res[i] = (A >> (24 - i * 8)) & 0x000000ff;
		e->res[i + 4] = (B >> (24 - i * 8)) & 0x000000ff;
		e->res[i + 8] = (C >> (24 - i * 8)) & 0x000000ff;
		e->res[i + 12] = (D >> (24 - i * 8)) & 0x000000ff;
		e->res[i + 16] = (E >> (24 - i * 8)) & 0x000000ff;
		e->res[i + 20] = (F >> (24 - i * 8)) & 0x000000ff;
		e->res[i + 24] = (G >> (24 - i * 8)) & 0x000000ff;
		e->res[i + 28] = (H >> (24 - i * 8)) & 0x000000ff;
	}
}

static void			sha256_print_res(t_ssl_wrap *w, t_ssl_file *f,
					t_ssl_sha256 *e)
{
	int				j;

	j = -1;
	if (QUIET_M == true && PRINT_M == false)
	{
		while (++j < 32)
			ft_printf("%02x", (unsigned char)e->res[j]);
		WS("");
		return ;
	}
	ft_strcpy(w->hash_vers, "SHA256");
	print_res_routine(w, f);
	if (FILE_M == true && REVERSE_M == false)
		ft_printf("%s (%s) = ", w->hash_vers, f->name);
	while (++j < 32)
		ft_printf("%02x", (unsigned char)e->res[j]);
	if (REVERSE_M == true && f->name != NULL)
		ft_printf(" *%s", f->name);
	else if (REVERSE_M == true && f->name == NULL)
	{
		if (PRINT_M != true)
			ft_printf(" \"%s\"", f->file);
	}
	PRINT_M = false;
	WS("");
}

bool				sha256_routine(t_ssl_wrap *w, t_ssl_file *f)
{
	t_ssl_sha256	e;
	int				i;

	i = -1;
	ft_bzero(&e, sizeof(t_ssl_sha256));
	sha256_init(&e);
	while (++i < f->len)
	{
		e.buffer[e.datalen] = f->file[i];
		e.datalen++;
		if (e.datalen == 64)
		{
			sha256_washing(&e);
			e.datalen = 0;
			e.bitlen += 512;
		}
	}
	sha256_end(&e);
	sha256_print_res(w, f, &e);
	return (true);
}
