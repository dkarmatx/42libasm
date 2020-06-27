/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:29:07 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 16:03:05 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include "libasm.h"

void	check_memset_case_1(void)
{
	char	buf1[64];
	char	buf2[64];

	assert(memset(buf1, 'a', 64) == buf1);
	assert(memset(buf1 + 2, 'b', 2) == buf1 + 2);
	assert(memset(buf1 + 5, 100050, 51) == buf1 + 5);
	assert(memset(buf1 + 16, 'z', 10) == buf1 + 16);
	assert(ft_memset(buf2, 'a', 64) == buf2);
	assert(ft_memset(buf2 + 2, 'b', 2) == buf2 + 2);
	assert(ft_memset(buf2 + 5, 100050, 51) == buf2 + 5);
	assert(ft_memset(buf2 + 16, 'z', 10) == buf2 + 16);
	assert(ft_memset(buf2 + 63, 'z', 0) == buf2 + 63);
	assert(memcmp(buf1, buf2, 64) == 0);
}
