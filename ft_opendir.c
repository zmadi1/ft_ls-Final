/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:07:57 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/19 15:06:01 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"
#include <stdio.h>

int		count_dir(char *dir)
{
	int				i;
	DIR				*curdir;
	struct dirent	*files;

	i = 0;
	curdir = opendir(dir);
	while ((files = readdir(curdir)) != NULL)
	{
		if (files->d_type == 4)
			i++;
	}
	closedir(curdir);
	return (i);
}

char	**temporary_function(char **dir, char **temp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dir[i] != NULL)
		i++;
	while (temp[j] != NULL)
		dir[i++] = ft_strdup(temp[j++]);
	dir[i] = NULL;
	ft_sort(dir);
	ft_delete(temp);
	return (dir);
}

void	ft_content_flags(char **new, char **temp, char **dir, t_flags *flag)
{
	ft_sort(new);
	if (flag->flag_t == '1')
		new = ft_time_sort(new, *dir);
	if (flag->flag_lr == '1')
		new = ft_reverse(new);
	dir = temporary_function(dir, temp);
	ft_putchar('\n');
}

char	**ft_content(char **new, t_flags *flag, char **dir)
{
	DIR		*curdir;
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * 256);
	new = (char **)malloc(sizeof(char *) * count(dir[0]) + 1);
	if (!(curdir = opendir(*dir)))
		ft_protector(new, *dir);
	if (curdir)
	{
		closedir(curdir);
		ft_content_while(new, temp, flag, dir);
	}
	ft_content_flags(new, temp, dir, flag);
	return (new);
}
