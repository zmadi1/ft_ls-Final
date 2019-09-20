/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:43:19 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/19 08:16:42 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

char	*ft_path(char *filename, char *dir)
{
	char *ret;
	char *ptr;

	ret = NULL;
	ptr = NULL;
	ptr = ft_strjoin(dir, "/");
	ret = ft_strjoin(ptr, filename);
	ft_strdel(&ptr);
	return (ret);
}
