/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 02:49:41 by kbensado          #+#    #+#             */
/*   Updated: 2018/08/05 02:50:00 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"
#include "../inc/md5.h"

void				first_wash(t_ssl_md5 *e)
{
	FF(TA, TB, TC, TD, e->b_endian[0], 7, 0xd76aa478);
	FF(TD, TA, TB, TC, e->b_endian[1], 12, 0xe8c7b756);
	FF(TC, TD, TA, TB, e->b_endian[2], 17, 0x242070db);
	FF(TB, TC, TD, TA, e->b_endian[3], 22, 0xc1bdceee);
	FF(TA, TB, TC, TD, e->b_endian[4], 7, 0xf57c0faf);
	FF(TD, TA, TB, TC, e->b_endian[5], 12, 0x4787c62a);
	FF(TC, TD, TA, TB, e->b_endian[6], 17, 0xa8304613);
	FF(TB, TC, TD, TA, e->b_endian[7], 22, 0xfd469501);
	FF(TA, TB, TC, TD, e->b_endian[8], 7, 0x698098d8);
	FF(TD, TA, TB, TC, e->b_endian[9], 12, 0x8b44f7af);
	FF(TC, TD, TA, TB, e->b_endian[10], 17, 0xffff5bb1);
	FF(TB, TC, TD, TA, e->b_endian[11], 22, 0x895cd7be);
	FF(TA, TB, TC, TD, e->b_endian[12], 7, 0x6b901122);
	FF(TD, TA, TB, TC, e->b_endian[13], 12, 0xfd987193);
	FF(TC, TD, TA, TB, e->b_endian[14], 17, 0xa679438e);
	FF(TB, TC, TD, TA, e->b_endian[15], 22, 0x49b40821);
}

void				second_wash(t_ssl_md5 *e)
{
	GG(TA, TB, TC, TD, e->b_endian[1], 5, 0xf61e2562);
	GG(TD, TA, TB, TC, e->b_endian[6], 9, 0xc040b340);
	GG(TC, TD, TA, TB, e->b_endian[11], 14, 0x265e5a51);
	GG(TB, TC, TD, TA, e->b_endian[0], 20, 0xe9b6c7aa);
	GG(TA, TB, TC, TD, e->b_endian[5], 5, 0xd62f105d);
	GG(TD, TA, TB, TC, e->b_endian[10], 9, 0x02441453);
	GG(TC, TD, TA, TB, e->b_endian[15], 14, 0xd8a1e681);
	GG(TB, TC, TD, TA, e->b_endian[4], 20, 0xe7d3fbc8);
	GG(TA, TB, TC, TD, e->b_endian[9], 5, 0x21e1cde6);
	GG(TD, TA, TB, TC, e->b_endian[14], 9, 0xc33707d6);
	GG(TC, TD, TA, TB, e->b_endian[3], 14, 0xf4d50d87);
	GG(TB, TC, TD, TA, e->b_endian[8], 20, 0x455a14ed);
	GG(TA, TB, TC, TD, e->b_endian[13], 5, 0xa9e3e905);
	GG(TD, TA, TB, TC, e->b_endian[2], 9, 0xfcefa3f8);
	GG(TC, TD, TA, TB, e->b_endian[7], 14, 0x676f02d9);
	GG(TB, TC, TD, TA, e->b_endian[12], 20, 0x8d2a4c8a);
}

void				third_wash(t_ssl_md5 *e)
{
	HH(TA, TB, TC, TD, e->b_endian[5], 4, 0xfffa3942);
	HH(TD, TA, TB, TC, e->b_endian[8], 11, 0x8771f681);
	HH(TC, TD, TA, TB, e->b_endian[11], 16, 0x6d9d6122);
	HH(TB, TC, TD, TA, e->b_endian[14], 23, 0xfde5380c);
	HH(TA, TB, TC, TD, e->b_endian[1], 4, 0xa4beea44);
	HH(TD, TA, TB, TC, e->b_endian[4], 11, 0x4bdecfa9);
	HH(TC, TD, TA, TB, e->b_endian[7], 16, 0xf6bb4b60);
	HH(TB, TC, TD, TA, e->b_endian[10], 23, 0xbebfbc70);
	HH(TA, TB, TC, TD, e->b_endian[13], 4, 0x289b7ec6);
	HH(TD, TA, TB, TC, e->b_endian[0], 11, 0xeaa127fa);
	HH(TC, TD, TA, TB, e->b_endian[3], 16, 0xd4ef3085);
	HH(TB, TC, TD, TA, e->b_endian[6], 23, 0x04881d05);
	HH(TA, TB, TC, TD, e->b_endian[9], 4, 0xd9d4d039);
	HH(TD, TA, TB, TC, e->b_endian[12], 11, 0xe6db99e5);
	HH(TC, TD, TA, TB, e->b_endian[15], 16, 0x1fa27cf8);
	HH(TB, TC, TD, TA, e->b_endian[2], 23, 0xc4ac5665);
}

void				final_wash(t_ssl_md5 *e)
{
	II(TA, TB, TC, TD, e->b_endian[0], 6, 0xf4292244);
	II(TD, TA, TB, TC, e->b_endian[7], 10, 0x432aff97);
	II(TC, TD, TA, TB, e->b_endian[14], 15, 0xab9423a7);
	II(TB, TC, TD, TA, e->b_endian[5], 21, 0xfc93a039);
	II(TA, TB, TC, TD, e->b_endian[12], 6, 0x655b59c3);
	II(TD, TA, TB, TC, e->b_endian[3], 10, 0x8f0ccc92);
	II(TC, TD, TA, TB, e->b_endian[10], 15, 0xffeff47d);
	II(TB, TC, TD, TA, e->b_endian[1], 21, 0x85845dd1);
	II(TA, TB, TC, TD, e->b_endian[8], 6, 0x6fa87e4f);
	II(TD, TA, TB, TC, e->b_endian[15], 10, 0xfe2ce6e0);
	II(TC, TD, TA, TB, e->b_endian[6], 15, 0xa3014314);
	II(TB, TC, TD, TA, e->b_endian[13], 21, 0x4e0811a1);
	II(TA, TB, TC, TD, e->b_endian[4], 6, 0xf7537e82);
	II(TD, TA, TB, TC, e->b_endian[11], 10, 0xbd3af235);
	II(TC, TD, TA, TB, e->b_endian[2], 15, 0x2ad7d2bb);
	II(TB, TC, TD, TA, e->b_endian[9], 21, 0xeb86d391);
}
