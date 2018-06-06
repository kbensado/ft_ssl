/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:01:14 by kbensado          #+#    #+#             */
/*   Updated: 2018/06/06 18:31:58 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"

/*
**	on va utiliser le buffer[64] pour appliquer notre cryptage
**	chunk par chunk et additionner a chaque fois
**	le resultat dans les states
**	tmp pour stocker les states et iterer avant d'append
**	b_endian assume le role de buffer pour la conversion big/little endian
**
**
**
*/

# define A e->state[0]
# define B e->state[1]
# define C e->state[2]
# define D e->state[3]
# define TA e->tmp[0]
# define TB e->tmp[1]
# define TC e->tmp[2]
# define TD e->tmp[3]

# define RLEFT(a, b) ((a << b) | (a >> (32 - b)))

# define FF(a,b,c,d,m,s,t) {a += F(b, c, d) + m + t; a = b + ROTLEFT(a, s);}

# define GG(a,b,c,d,m,s,t) { a += G(b,c,d) + m + t; a = b + ROTLEFT(a,s);}
# define HH(a,b,c,d,m,s,t) { a += H(b,c,d) + m + t; a = b + ROTLEFT(a,s);}
# define II(a,b,c,d,m,s,t) { a += I(b,c,d) + m + t; a = b + ROTLEFT(a,s);}

# define F(x,y,z) ((x & y) | (~x & z))
# define G(x,y,z) ((x & z) | (y & ~z))
# define H(x,y,z) (x ^ y ^ z)
# define I(x,y,z) (y ^ (x | ~z))

typedef struct	s_ssl_md5
{
	uint8_t		buffer[64];
	uint32_t	datalen;
	uint32_t	state[4];
	uint32_t	bitlen[2];

	uint32_t	tmp[4];
	uint32_t	b_endian[16];

}				t_ssl_md5;

#endif
