/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:42:20 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/16 14:17:16 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

int	count(char *dir)
{
	int				i;
	DIR				*curdir;
	struct dirent	*files;

	i = 0;
	curdir = opendir(dir);
	if (!curdir)
		return (1);
	while ((files = readdir(curdir)) != NULL)
		i++;
	if (curdir)
		closedir(curdir);
	return (i);
}
