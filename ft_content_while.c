/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_while.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 07:18:19 by zmadi             #+#    #+#             */
/*   Updated: 2019/11/19 11:00:35 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

// void	ft_content_temp(char **temp, struct dirent *files, int j, char *dir)
// {
// 	temp[j] = ft_path(files->d_name, dir);
// 	//ft_putendl("----------");
// 	temp[j] = NULL;
// }

// int		ft_content_val(t_flags *flag, struct dirent *files)
// {
// 	if (flag->flag_ur == '1' && files->d_type == 4
// 	&& (ft_strcmp(files->d_name, ".") != 0)
// 	&& (ft_strcmp(files->d_name, "..") != 0))
// 		return (1);
// 	else
// 		return (0);
// }

void	ft_content_while(char **new, /*char **temp*/ t_flags *flag, char **dir)
{
	int				i;
	int				j;
	struct dirent	*files;
	DIR				*curdir;

	i = 0;
	j = 0;
	curdir = opendir(*dir);
	while ((files = readdir(curdir)) != NULL)
	{
		
		if (flag->flag_a == '0' && files->d_name[0] != '.')
		{
			new[i++] = ft_strdup(files->d_name);
			// if ((ft_content_val(flag, files)) == 1)
			// 	ft_content_temp(/*temp*/ files, j++, *dir);
		}
		if (flag->flag_a == '1')
		{
			new[i++] = ft_strdup(files->d_name);
			// if ((ft_content_val(flag, files)) == 1)
			// 	ft_content_temp(/*temp*/ files, j++, *dir);
		}
	}
	new[i] = NULL;
	closedir(curdir);
}
