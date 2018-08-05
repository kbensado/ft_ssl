/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 00:09:03 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/05 02:44:08 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_H
# define SHA_H

# include "ft_ssl.h"

# define RRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))
# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define EP0(x) (RRIGHT(x,2) ^ RRIGHT(x,13) ^ RRIGHT(x,22))
# define EP1(x) (RRIGHT(x,6) ^ RRIGHT(x,11) ^ RRIGHT(x,25))
# define SIG0(x) (RRIGHT(x,7) ^ RRIGHT(x,18) ^ ((x) >> 3))
# define SIG1(x) (RRIGHT(x,17) ^ RRIGHT(x,19) ^ ((x) >> 10))

# define A e->state[0]
# define B e->state[1]
# define C e->state[2]
# define D e->state[3]
# define E e->state[4]
# define F e->state[5]
# define G e->state[6]
# define H e->state[7]
# define TA e->tmp[0]
# define TB e->tmp[1]
# define TC e->tmp[2]
# define TD e->tmp[3]
# define TE e->tmp[4]
# define TF e->tmp[5]
# define TG e->tmp[6]
# define TH e->tmp[7]

typedef struct	s_ssl_sha256
{
	unsigned char		buffer[64];
	uint32_t			datalen;
	uint32_t			state[8];
	unsigned long long	bitlen;
	uint32_t			tmp[8];
	uint32_t			b_endian[64];
	char				res[32];

}				t_ssl_sha256;

void			sha256_washing(t_ssl_sha256 *e);
void			sha256_init_washing(t_ssl_sha256 *e);
void			sha256_init(t_ssl_sha256 *e);
void			watch_done_routine(t_ssl_sha256 *e);
void			sha256_end(t_ssl_sha256 *e);
void			sha256_end_set(t_ssl_sha256 *e);
void			watch_done(t_ssl_sha256 *e);

#endif
