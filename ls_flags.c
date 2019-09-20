/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:50:14 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/19 15:12:21 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void	ft_flag_active(t_flags *flags, char *str)
{
	if (flags->flag_l == '1' || flags->flag_a == '1' || flags->flag_lr == '1'
			|| flags->flag_t == '1' || flags->flag_ur == '1')
		flags->flag_active = '1';
	if (flags->flag_active == '0')
	{
		flags->flag_err = '1';
		ft_putstr("ls: invalid option --");
		ft_putstr(str);
		ft_putstr("\nUse: ls [ - ] [alrtnogR] [file ..]\n");
		exit(0);
	}
}

int		check_flags(char **str, t_flags *flags)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
		{
			if (ft_strchr(str[i], 'l'))
				flags->flag_l = '1';
			if (ft_strchr(str[i], 'a'))
				flags->flag_a = '1';
			if (ft_strchr(str[i], 'r'))
				flags->flag_lr = '1';
			if (ft_strchr(str[i], 't'))
				flags->flag_t = '1';
			if (ft_strchr(str[i], 'R'))
				flags->flag_ur = '1';
			ft_flag_active(flags, str[i]);
		}
		i++;
	}
	return (1);
}
