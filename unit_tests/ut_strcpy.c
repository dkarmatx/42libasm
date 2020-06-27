/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:35:31 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 11:50:51 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include "libasm.h"

void	check_strcpy_case_1(void)
{
	char		d1[48];
	char		d2[48];

	memcpy(d1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 48);
	memcpy(d2, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 48);
	assert(strcpy(d1, "101230123") == d1);
	assert(ft_strcpy(d2, "101230123") == d2);
	assert(memcmp(d1, d2, 48) == 0);
	assert(strcpy(d1 + 10, "hh") == d1 + 10);
	assert(ft_strcpy(d2 + 10, "hh") == d2 + 10);
	assert(memcmp(d1, d2, 48) == 0);
	assert(strcpy(d1 + 10, "") == d1 + 10);
	assert(ft_strcpy(d2 + 10, "") == d2 + 10);
	assert(memcmp(d1, d2, 48) == 0);
	assert(strcpy(d1, "hsdjhsjdhsjdhjshdjshdjshjshdjshdjshdjsdhsss") == d1);
	assert(ft_strcpy(d2, "hsdjhsjdhsjdhjshdjshdjshjshdjshdjshdjsdhsss") == d2);
	assert(memcmp(d1, d2, 48) == 0);
}
