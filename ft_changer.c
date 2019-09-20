/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:17:51 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/17 11:17:29 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

char	*ft_changer(char **ptr)
{
	int			i;
	char		*str;
	struct stat buffer;

	i = 1;
	str = NULL;
	while (ptr[i])
	{
		if (stat(ptr[i], &buffer) == 0)
		{
			str = ft_strdup(ptr[i]);
			break ;
		}
		i++;
	}
	if (str == NULL)
		str = ft_strdup(".");
	return (str);
}
