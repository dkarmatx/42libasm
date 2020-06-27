/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 08:06:17 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 09:53:48 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include "libasm.h"

void	check_memchr_case_1(void)
{
	const char	buf_1[] = "1234567890";
	const char	buf_2[] = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhha";
	const char	buf_3[] = "hhhhhhhhhhhhhhhhhhhhhhhhhhahhhhhhhhhhhhhhhhhhhhhha";
	const char	buf_4[] = "hhhhhhhhhhhhhhhhhhhhhh\xff\xff\xff\xfahhhhhhhhhha";

	assert(ft_memchr(buf_1, '5', 11) == memchr(buf_1, '5', 11));
	assert(ft_memchr(buf_1, '7', 6) == memchr(buf_1, '7', 6));
	assert(ft_memchr(buf_1, '1', 1) == memchr(buf_1, '1', 1));
	assert(ft_memchr(buf_1, '2', 4) == memchr(buf_1, '2', 4));
	assert(ft_memchr(buf_2, 'l', 51) == memchr(buf_2, 'l', 51));
	assert(ft_memchr(buf_2, 'a', 51) == memchr(buf_2, 'a', 51));
	assert(ft_memchr(buf_2 + 1, 'a', 10000) == memchr(buf_2 + 1, 'a', 10000));
	assert(ft_memchr(buf_2, 'a', 49) == memchr(buf_2, 'a', 49));
	assert(ft_memchr(buf_3, 'a', 1000) == memchr(buf_3, 'a', 1000));
	assert(ft_memchr(buf_3, 'a', 26) == memchr(buf_3, 'a', 26));
	assert(ft_memchr(buf_4, '\xfa', 38) == memchr(buf_4, '\xfa', 38));
}
