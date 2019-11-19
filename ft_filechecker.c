/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filechecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 08:38:13 by zmadi             #+#    #+#             */
/*   Updated: 2019/11/19 11:58:23 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_flags.h"

void	ft_rights(struct stat mode)
{
	char	*i;

	if (!(i = malloc(sizeof(i) * 10)))
		return ;
	i[0] = (S_IRUSR & mode.st_mode) ? 'r' : '-';
	i[1] = (S_IWUSR & mode.st_mode) ? 'w' : '-';
	i[2] = (S_IXUSR & mode.st_mode) ? 'x' : '-';
	i[3] = (S_IRGRP & mode.st_mode) ? 'r' : '-';
	i[4] = (S_IWGRP & mode.st_mode) ? 'w' : '-';
	i[5] = (S_IXGRP & mode.st_mode) ? 'x' : '-';
	i[6] = (S_IROTH & mode.st_mode) ? 'r' : '-';
	i[7] = (S_IWOTH & mode.st_mode) ? 'w' : '-';
	i[8] = (S_IXOTH & mode.st_mode) ? 'x' : '-';
	i[9] = '\0';
	ft_putstr(i);
	ft_strdel(&i);
}

void	handle_date(struct stat s)
{
	char	**date;

	date = ft_strsplit(ctime(&s.st_mtimespec.tv_sec), ' ');
	ft_putstr(date[1]);
	ft_putstr(" ");
	!date[2][1] ? ft_putchar(' ') : 0;
	ft_putstr(date[2]);
	ft_putstr(" ");
	date[3][5] = '\0';
	date[4][4] = '\0';
	ft_putstr(date[3]);
	ft_delete(date);
}

void	group_rights(struct stat ptr)
{
	struct group	*grp;

	if (!(grp = getgrgid(ptr.st_gid)))
		ft_putnbr(ptr.st_gid);
	else
	{
		ft_putstr(grp->gr_name);
	}
	ft_space(ft_count_nbr(ptr.st_size), 6);
	ft_putnbr(ptr.st_size);
	ft_putchar(' ');
}

int		usi_rights(char *ptr, char *dir)
{
	struct stat		user;
	struct passwd	*parent;
	char			*str;

	if ((ft_strcmp(ptr, dir)) == 0)
		lstat((str = ft_path(ptr, ".")), &user);
	else
		lstat((str = ft_path(ptr, dir)), &user);
	ft_space(ft_count_nbr(user.st_nlink), 4);
	ft_putnbr(user.st_nlink);
	ft_putchar(' ');
	parent = getpwuid(user.st_uid);
	ft_putstr(parent->pw_name);
	ft_putchar(' ');
	group_rights(user);
	handle_date(user);
	ft_putchar(' ');
	ft_strdel(&str);
	return (0);
}

void	ft_file_info(char **ptr, char *dir)
{
	struct stat checker;
	int			i;
	char		*str;

	i = 0;
	display_blockcount(blockcount(ptr));
	// ft_putstr("total ");
	// ft_putnbr(blockcount(ptr));
	// ft_putendl(" ");
	while (ptr[i] != NULL)
	{
		lstat((str = ft_path(ptr[i], dir)), &checker);
		if (S_ISBLK(checker.st_mode))
			ft_putchar('b');
		else if (S_ISCHR(checker.st_mode))
			ft_putchar('c');
		else if (S_ISDIR(checker.st_mode))
			ft_putchar('d');
		else if (S_ISREG(checker.st_mode))
			ft_putchar('-');
		else if (S_ISLNK(checker.st_mode))
			ft_putchar('l');
		else
			ft_putchar('?');
		ft_rights(checker);
		usi_rights(ptr[i], dir);
		ft_putendl(ptr[i++]);
		ft_strdel(&str);
	}
}
