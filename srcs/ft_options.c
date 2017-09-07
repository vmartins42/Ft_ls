/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 10:11:25 by vmartins          #+#    #+#             */
/*   Updated: 2017/07/13 13:26:25 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_rights(mode_t mode)
{
	(mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	(mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	(mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	(mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
	ft_putchar(' ');
}

void	print_type(mode_t mode)
{
	if (S_ISREG(mode))
		ft_putchar('-');
	else if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else
		ft_putchar('s');
}

void	print_options(char *str, int size)
{
	int		n;

	n = size - ft_strlen(str);
	ft_putstr(str);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}

void	print_date_modif(time_t date_modif)
{
	char	*str;
	char	*str2;

	str = ctime(&date_modif);
	if (time(NULL) - 15778800 > date_modif || date_modif > time(NULL))
	{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str, 20, 4);
		str = ft_strsub(str, 4, 6);
		str = ft_strjoin(str, "  ");
		str = ft_strjoin(str, str2);
		ft_strdel(&str2);
	}
	else
		str = ft_strsub(str, 4, 12);
	str[12] = '\0';
	ft_putstr(str);
	ft_putchar(' ');
	ft_strdel(&str);
}
