/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <wp3d3p@yandex.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 03:45:35 by hgranule          #+#    #+#             */
/*   Updated: 2020/07/02 11:52:01 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <sys/types.h>

int		ft_write(int fd, const void *ptr, size_t len);
ssize_t	ft_read(int fd, void *buff, size_t sz);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *m1, const void *m2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
void	*ft_memchr(const void *m, int c, size_t len);
void	*ft_memset(void *m, int c, size_t len);

#endif
