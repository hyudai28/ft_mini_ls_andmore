/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utilities01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:40:16 by hyudai            #+#    #+#             */
/*   Updated: 2020/12/04 17:41:47 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((*str1 != '\0') && i < n - 1)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		i++;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}