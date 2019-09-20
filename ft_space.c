/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:04:31 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/16 12:05:29 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void	ft_space(int i, int b)
{
	int a;

	a = 0;
	while (a < (b - i))
	{
		ft_putchar(' ');
		a++;
	}
}

int		ft_count_nbr(int i)
{
	int a;

	a = 0;
	while (i /= 10)
		a++;
	return (a);
}
