/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:57:17 by vmartins          #+#    #+#             */
/*   Updated: 2017/08/21 11:21:30 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ft_get_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void		init_size_l(t_option *option)
{
	option->link = 0;
	option->user = 0;
	option->group = 0;
	option->size = 0;
	option->min = 0;
	option->maj = 0;
	option->len_min = 0;
	option->len_maj = 0;
}

static	void	size_second(t_option *option, struct stat *sb)
{
	size_t		len;

	if (getpwuid(sb->st_uid))
	{
		len = ft_strlen(getpwuid(sb->st_uid)->pw_name);
		(len > option->user) ? option->user = len : 0;
	}
	if (getgrgid(sb->st_gid))
	{
		len = ft_strlen(getgrgid(sb->st_gid)->gr_name);
		(len > option->group) ? option->group = len : 0;
	}
}

static void		size_one(t_option *option, struct stat *sb)
{
	int		len;

	len = ft_get_len(sb->st_nlink);
	(len > option->link) ? option->link = len : 0;
	len = ft_get_len(sb->st_size);
	(len > option->size) ? option->size = len : 0;
	len = ft_get_len(minor(sb->st_rdev));
	(len > option->min) ? option->min = len : 0;
	len = ft_get_len(major(sb->st_rdev));
	(len > option->maj) ? option->maj = len : 0;
}

void			stock_size(t_option *option, t_list *list, char *path_files)
{
	t_list			*files;
	struct stat		sb;
	char			*path_and_file;
	char			*temp;

	files = list;
	init_size_l(option);
	while (files)
	{
		path_and_file = ft_strjoin(path_files, files->content);
		lstat(path_and_file, &sb);
		temp = files->content;
		if (temp[0] != '.')
			option->total += sb.st_blocks;
		size_one(option, &sb);
		size_second(option, &sb);
		files = files->next;
	}
	free(files);
}
