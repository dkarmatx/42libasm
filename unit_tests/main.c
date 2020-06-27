/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 08:04:31 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 12:35:20 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_libasm.h"

int		main(void)
{
	check_memchr_case_1();
	check_memcmp_case_1();
	check_memcmp_case_2();
	check_memcpy_case_1();
	check_memcpy_case_2();
	check_memset_case_1();
	check_strcmp_case_1();
	check_strcpy_case_1();
	check_strdup_case_1();
	check_strlen_case_1();
	check_read_write();
	return (0);
}
