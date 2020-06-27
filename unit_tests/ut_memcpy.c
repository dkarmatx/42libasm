/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:35:31 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 16:02:41 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include "libasm.h"

void	check_memcpy_case_1(void)
{
	const char	*ss = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	char		d1[48];
	char		d2[48];

	memcpy(d1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 48);
	memcpy(d2, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 48);
	assert(memcpy(d2, ss, 5) == d2);
	assert(memcpy(d2 + 10, ss, 5) == d2 + 10);
	assert(memcpy(d2 + 3, "c", 0) == d2 + 3);
	assert(memcpy(d2 + 18, ss, 7) == d2 + 18);
	assert(ft_memcpy(d1, ss, 5) == d1);
	assert(ft_memcpy(d1 + 10, ss, 5) == d1 + 10);
	assert(ft_memcpy(d1 + 3, "c", 0) == d1 + 3);
	assert(ft_memcpy(d1 + 18, ss, 7) == d1 + 18);
	assert(memcmp(d1, d2, 48) == 0);
}

void	check_memcpy_case_2(void)
{
	assert(NULL == ft_memcpy(NULL, NULL, 0));
	assert(NULL == ft_memcpy(NULL, "12", 0));
	assert(NULL == ft_memcpy(NULL, NULL, 4));
}
