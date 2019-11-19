/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:35:20 by zmadi             #+#    #+#             */
/*   Updated: 2019/11/19 09:00:33 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

t_flags	*ft_flag_ini(void)
{
	t_flags *flag;

	flag = (t_flags *)malloc(sizeof(t_flags));
	flag->flag_l = '0';
	flag->flag_a = '0';
	flag->flag_ur = '0';
	flag->flag_lr = '0';
	flag->flag_t = '0';
	flag->flag_o = '0';
	flag->flag_n = '0';
	flag->flag_g = '0';
	flag->flag_err = '0';
	flag->flag_active = '0';
	return (flag);
}

char	**arguments_taker(char **str, int argument_counter)
{
	int		i;
	int		j;
	char	**s;

	i = 1;
	j = 0;
	s = (char **)malloc(sizeof(char *) * argument_counter * (256 * 256));
	while (str[i] != NULL)
	{
		if (str[i][0] != '-')
		{
			s[j] = ft_strdup(str[i]);
			j++;
		}
		i++;
	}
	s[j] = NULL;
	return (s);
}

void	ft_fixer(char **str)
{
	int j;

	j = 0;
	if (str[0] == NULL)
	{
		str[j] = ft_changer(str);
		str[j + 1] = NULL;
	}
}

void	ft_jump_argone(char **str, t_flags *flag)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = NULL;
	while (str[j] && flag->flag_err == '0' && j < (256 * 256))
	{
		if (array_counter(str) > 1)
		{
			ft_putstr(str[j]);
			ft_putendl(":");
		}
		new = ft_content(new, flag, &str[j]);
		i = 0;
		if (flag->flag_l == '1')
			ft_file_info(new, str[j]);
		while (new[i] != NULL && flag->flag_l == '0')
			ft_putendl(new[i++]);
		//ft_putchar('\n');
		j++;
	}
	ft_delete(new);
}

int		main(int ac, char **av)
{
	char	**str;
	t_flags *flag;
	int		i;
	int		j;

	j = 0;
	str = NULL;
	flag = ft_flag_ini();
	str = arguments_taker(av, ac);
	ft_sort(str);
	ft_fixer(str);
	if (ac >= 2)
	{
		check_flags(av, flag);
		ft_jump_argone(&str[j], flag);
	}
	i = 0;
	if (ac == 1)
	{
		ft_no_argument(str, flag);
	}
	ft_delete(str);
	return (0);
}
