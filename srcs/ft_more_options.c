/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 12:03:42 by vmartins          #+#    #+#             */
/*   Updated: 2017/07/13 13:24:51 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_link(t_option *option, mode_t mode)
{
	int		i;
	int		len;

	i = option->link;
	len = ft_get_len(mode);
	while (i-- > len)
		ft_putchar(' ');
	ft_putnbr(mode);
	ft_putchar(' ');
}

void	print_size(t_option *option, mode_t mode)
{
	int		i;
	int		len;

	i = option->size + (option->min + option->maj - \
			(option->len_min + option->len_maj));
	len = ft_get_len(mode);
	while (i-- > len)
		ft_putchar(' ');
	ft_putnbr(mode);
	ft_putchar(' ');
}

void	get_link(char *file, mode_t mode)
{
	char	*buffer;
	int		i;
	int		size;

	size = 255;
	if (!(buffer = (char *)malloc(sizeof(char) * size)))
		return ;
	if (!S_ISLNK(mode))
	{
		ft_putchar('\n');
		return ;
	}
	if ((i = readlink(file, buffer, size)) < 0)
		perror("readlink");
	else
	{
		buffer[i] = '\0';
		ft_putstr(" -> ");
		ft_putendl(buffer);
	}
	ft_strdel(&buffer);
}

void	print_min_and_maj(t_option *option, struct stat *sb)
{
	int		min;
	int		maj;

	min = ft_get_len(minor(sb->st_rdev));
	maj = ft_get_len(major(sb->st_rdev));
	option->len_min = min;
	option->len_maj = maj;
	while (maj++ < option->maj)
		ft_putchar(' ');
	ft_putnbr(major(sb->st_rdev));
	ft_putchar(' ');
	while (min++ < option->min)
		ft_putchar(' ');
	ft_putnbr(minor(sb->st_rdev));
	ft_putchar(' ');
}
