/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:24:51 by hyudai            #+#    #+#             */
/*   Updated: 2020/12/04 20:46:09 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct	s_ls_list
{
	char				*file;
	struct timespec		last_update;
} 				t_ls_list;

void	sort_file(t_ls_list *array, size_t count);
void	input_struct(DIR *dir, t_ls_list *array_lst, size_t count);
void	output_struct(t_ls_list *array, size_t count);
size_t		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		struct_count(DIR *dir, char *path);

#endif