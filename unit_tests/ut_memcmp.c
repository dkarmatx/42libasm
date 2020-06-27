/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:35:31 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 15:13:58 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include "libasm.h"

void	check_memcmp_case_1(void)
{
	const char	*m1_1 = "abcabcabd";
	const char	*m1_2 = "abcabcabc";
	const char	*m2_1 = "aaaaaaaaaaaa";
	const char	*m2_2 = "aaaaa";
	const char	*m3_1 = "";

	assert(ft_memcmp(m1_1, m1_2, 10) > 0);
	assert(ft_memcmp(m1_1, m1_2, 3) == 0);
	assert(ft_memcmp(m1_1, m1_2, 0) == 0);
	assert(ft_memcmp(m1_1, m1_2, 8) == 0);
	assert(ft_memcmp(m2_1, m2_2, 10000) > 0);
	assert(ft_memcmp(m2_2, m2_1, 10000) < 0);
	assert(ft_memcmp(m2_1, m2_2, 4) == 0);
	assert(ft_memcmp(m3_1, m3_1, 1) == 0);
}

void	check_memcmp_case_2(void)
{
	const char	*m1 = "hhhhhhhaaaaaaaaahhhhhhhaaaa\xff\xff\xffz0000005556";
	const char	*m2 = "hhhhhhhaaaaaaaaahhhhhhhaaaa\xfa\xff\xffz0000005556";

	assert(ft_memcmp(m1, m2, 27) == 0);
	assert(ft_memcmp(m2, m1, 27) == 0);
	assert(ft_memcmp(m2, m1, 28) < 0);
	assert(ft_memcmp(m2, m1, 1000) < 0);
	assert(ft_memcmp(m1, m2, 10000) > 0);
}
