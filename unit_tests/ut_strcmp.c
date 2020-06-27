/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:35:16 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 15:15:49 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include "libasm.h"

void	check_strcmp_case_1(void)
{
	const char *s11 = "abcdefgh";
	const char *s12 = "abcdefgh";
	const char *s21 = "aaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhbaaaaaaaaaaaaaaaaaa";
	const char *s22 = "aaaaaaaaaaaaaaaaaaaaaaaaaaahhhhhhhhhaaaaaaaaaaaaaaaaaaa";
	const char *es = "";

	assert(ft_strcmp(s11, s12) == 0);
	assert(ft_strcmp(s12, s11) == 0);
	assert(ft_strcmp(s21, s22) > 0);
	assert(ft_strcmp(s22, s21) < 0);
	assert(ft_strcmp(s11, s22) > 0);
	assert(ft_strcmp(es, s22) < 0);
	assert(ft_strcmp(es, es) == 0);
}
