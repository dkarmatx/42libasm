/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_read_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:03:15 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 12:37:16 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "libasm.h"

#define TMP_FILENAME "tmp_file.txt"

static void		write_some(void)
{
	const int	fd = open(TMP_FILENAME, O_WRONLY);

	errno = 0;
	assert(ft_write(fd, "abcdefgh", 8) == 8);
	assert(ft_write(fd, "000000", 6) == 6);
	write(fd, "std_sys_call", 12);
	assert(ft_write(fd, "a", 1) == 1);
	assert(ft_write(fd, "bc", 2) == 2);
	assert(ft_write(fd, "def", 3) == 3);
	assert(errno == 0);
	close(fd);
}

static ssize_t	read_n(int fd, char *buf,
				size_t len, ssize_t (*f_rd)(int, void *, size_t))
{
	const ssize_t	rd = f_rd(fd, buf, len);

	buf[rd] = '\0';
	return (rd);
}

static void		read_some(void)
{
	const int	fd = open(TMP_FILENAME, O_RDONLY);
	char		buff[1024];

	errno = 0;
	assert(read_n(fd, buff, 14, &ft_read) == 14);
	assert(strcmp("abcdefgh000000", buff) == 0);
	assert(read_n(fd, buff, 12, &read) == 12);
	assert(strcmp("std_sys_call", buff) == 0);
	assert(read_n(fd, buff, 1024, &ft_read) == 6);
	assert(strcmp("abcdef", buff) == 0);
	assert(read(fd, buff, 10) == 0);
	assert(ft_read(fd, buff, 10) == 0);
	assert(errno == 0);
	close(fd);
}

static void		check_errno(void)
{
	int			o_value;
	ssize_t		rvalue;

	errno = 0;
	rvalue = read(-1, NULL, 0);
	o_value = errno;
	assert(rvalue == ft_read(-1, NULL, 0));
	assert(o_value == errno);
	errno = 0;
	rvalue = read(0, "", -1);
	o_value = errno;
	assert(rvalue == ft_read(0, "", -1));
	assert(o_value == errno);
	errno = 0;
	rvalue = write(-1, "HELLO", 10);
	o_value = errno;
	assert(rvalue == ft_write(-1, "HELLO", 10));
	assert(o_value == errno);
}

void			check_read_write(void)
{
	close(creat(TMP_FILENAME, 0644));
	write_some();
	read_some();
	check_errno();
	remove(TMP_FILENAME);
}
