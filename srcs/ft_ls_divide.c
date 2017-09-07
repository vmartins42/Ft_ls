/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 09:56:50 by vmartins          #+#    #+#             */
/*   Updated: 2017/08/21 11:12:28 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_ft_ls_l(t_option *option, char *file, char *path_files,
		struct stat *sb)
{
	char	*path_and_file;

	path_and_file = ft_strjoin(path_files, file);
	lstat(path_and_file, sb);
	(ft_strcmp(path_and_file, "/dev/fd/3") == 0) ? lstat(".", sb) : 0;
	print_type(sb->st_mode);
	print_rights(sb->st_mode);
	print_link(option, sb->st_nlink);
	if (getpwuid(sb->st_uid))
		print_options(getpwuid(sb->st_uid)->pw_name, option->user);
	else
		print_options(ft_itoa(sb->st_uid), option->user);
	if (getgrgid(sb->st_gid))
		print_options(getgrgid(sb->st_gid)->gr_name, option->group);
	else
		print_options(ft_itoa(sb->st_gid), option->group);
	if (S_ISCHR(sb->st_mode) || S_ISBLK(sb->st_mode))
		print_min_and_maj(option, sb);
	else
		print_size(option, sb->st_size);
	print_date_modif(sb->st_mtime);
	ft_putstr(file);
	get_link(path_and_file, sb->st_mode);
	ft_strdel(&path_and_file);
}

void	ft_ls_l(t_option *option, t_list *list, int directory, char *path_files)
{
	t_list		*files;
	char		*str;
	struct stat	sb;

	files = list;
	stock_size(option, files, path_files);
	if (directory && files)
	{
		if (option->total != 0)
		{
			ft_putstr("total ");
			ft_putnbr(option->total);
			ft_putchar('\n');
		}
	}
	while (files)
	{
		str = files->content;
		if (!(option->a != 1 && str[0] == '.'))
			print_ft_ls_l(option, files->content, path_files, &sb);
		files = files->next;
	}
}

void	ft_ls_simple(t_option *option, t_list *list, char *path_files)
{
	t_list		*path;
	struct stat	sb;
	char		*str;
	char		*path_and_file;

	path = list;
	while (path)
	{
		path_and_file = ft_strjoin(path_files, path->content);
		lstat(path_and_file, &sb);
		str = path->content;
		if (!(option->a != 1 && str[0] == '.'))
			ft_putendl(path->content);
		path = path->next;
		ft_strdel(&path_and_file);
	}
}

void	recursivite(t_option *option, char *path)
{
	struct dirent	*file;
	DIR				*dir;
	t_list			*files_inside;

	files_inside = NULL;
	file = NULL;
	ft_putchar('\n');
	ft_putendl(ft_strjoin(path, ":"));
	if ((dir = opendir(path)))
	{
		while ((file = readdir(dir)))
			ft_lstpushback(&files_inside, file->d_name, \
					ft_strlen(file->d_name) + 1);
		closedir(dir);
		if (files_inside)
			display(option, files_inside, 1, path = ft_strjoin(path, "/"));
	}
	else
		ft_error(path, 0);
}

void	ft_ls_recursif(t_option *option, t_list *list, char *path_files)
{
	struct stat	sb;
	t_list		*files;
	char		*str;
	char		*path_and_file;

	files = list;
	(!files) ? ft_lstdel(&files, ft_del) : NULL;
	while (files)
	{
		path_and_file = ft_strjoin(path_files, files->content);
		lstat(path_and_file, &sb);
		str = files->content;
		if (S_ISDIR(sb.st_mode) && ft_strcmp(files->content, ".")
				&& ft_strcmp(files->content, "..")
				&& (!(option->a != 1 && str[0] == '.')))
			recursivite(option, path_and_file);
		files = files->next;
	}
}
