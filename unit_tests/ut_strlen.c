/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:35:31 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 11:50:43 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include "libasm.h"

void	check_strlen_case_1(void)
{
	const char	s1[] = "";
	const char	s2[] = "asdasdasdasdasdasdasdasdasdasdasdasdasdasd";
	const char	s3[] = "asdasdas\xff\xfe\xfa\xf0\x7f\xff\0\xff\xff\xfe";
	char		s4[1024 * 1024];

	memset(s4, '\xff', 1024 * 1024 - 1);
	s4[1024 * 1024 - 1] = '\0';
	assert(ft_strlen(s1) == strlen(s1));
	assert(ft_strlen(s2) == strlen(s2));
	assert(ft_strlen(s3) == strlen(s3));
	assert(ft_strlen(s4) == strlen(s4));
}
