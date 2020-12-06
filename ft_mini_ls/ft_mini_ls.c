/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:22:31 by hyudai            #+#    #+#             */
/*   Updated: 2020/12/04 20:45:55 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	input_struct(DIR *dir, t_ls_list *array_lst, size_t count)
{
	int		i;
	struct stat		time_dirent;
	struct dirent		*dent;

	i = 0;
	while((dent = readdir(dir)) != NULL)
	{
			lstat(dent->d_name, &time_dirent);
			(array_lst + i)->file = dent->d_name;
			(array_lst + i)->last_update = time_dirent.st_mtimespec;
			i++;
	}
	sort_file(array_lst, count);
}

void	sort_file(t_ls_list *array, size_t count)
{
	size_t		i;
	size_t		j;
	t_ls_list temp;

	i = 0;
	while (i < count)
	{
		j = i;
		while (j < count)
		{
			if ((array + i)->last_update.tv_sec > (array + j)->last_update.tv_sec)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
			j++;
		}
		i++;
	}
}

void	output_struct(t_ls_list *array, size_t count)
{
	size_t		i;

	i = 0;
	while (i < count)
	{
		if ((array+i)->file[0] != '.')
			ft_putendl_fd((array + i)->file, 1);
		i++;
	}
}

/*I don't know how to get path & perror*/
int		main(void)
{
	DIR					*dir;
	char				*path;
	size_t					file_count;
	t_ls_list		*array;

	path = "./";
	dir = opendir(path);
	if (dir == NULL)
	{
		perror(path);
		return (1);
	}
	file_count = struct_count(dir, path);
	array = (t_ls_list *)malloc(sizeof(t_ls_list) * (file_count + 1));
	input_struct(dir, array, file_count);
	output_struct(array, file_count);
	closedir(dir);
}