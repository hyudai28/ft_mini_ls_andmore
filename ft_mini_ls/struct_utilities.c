/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:44:35 by hyudai            #+#    #+#             */
/*   Updated: 2020/12/04 20:12:30 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int		struct_count(DIR *dir, char *path)
{
	int		count;
	struct dirent		*dent;

	count = 0;
	while ((dent = readdir(dir)) != NULL)
	{
		// if (dent->d_name != ".")
			count++;
	}
	closedir(dir);
	dir = opendir(path);
	if (dir == NULL)
	{
		perror(path);
		return (1);
	}
	return (count);
}