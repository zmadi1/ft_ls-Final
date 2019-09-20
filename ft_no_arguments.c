/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:05:22 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/18 14:29:40 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void	ft_no_argument(char **str, t_flags *flag)
{
	int		i;
	char	**new;

	i = 0;
	new = NULL;
	new = ft_content(new, flag, str);
	while (new[i] != NULL)
		ft_putendl(new[i++]);
	ft_delete(new);
}
