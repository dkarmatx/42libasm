/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:35:31 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 11:50:37 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "libasm.h"

void	check_strdup_case_1(void)
{
	const char	*o1 = "";
	const char	*o2 = "abcdefght";
	const char	*o3 = "1";
	const char	*o4 = "123123123123123123123123123123123123123123123asdasdasd";
	char		*str;

	str = ft_strdup(o1);
	assert(strcmp(o1, str) == 0);
	free(str);
	str = ft_strdup(o2);
	assert(strcmp(o2, str) == 0);
	free(str);
	str = ft_strdup(o3);
	assert(strcmp(o3, str) == 0);
	free(str);
	str = ft_strdup(o4);
	assert(strcmp(o4, str) == 0);
	free(str);
}
