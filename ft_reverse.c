/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:45:33 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/19 07:58:09 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

int		ft_count_array(char **new)
{
	int		a;

	a = 0;
	while (new[a] != NULL)
		a++;
	return (a);
}

char	**ft_reverse_delete(char **str, char **new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&new[i]);
		new[i] = ft_strdup(str[i]);
		i++;
	}
	return (new);
}

char	**ft_reverse(char **new)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = ft_count_array(new) - 1;
	str = (char **)malloc(sizeof(char *) * (j + 2));
	while (j >= 0)
		str[i++] = ft_strdup(new[j--]);
	str[i] = NULL;
	new = ft_reverse_delete(str, new);
	ft_delete(str);
	return (new);
}
