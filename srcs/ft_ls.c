/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:09:22 by vmartins          #+#    #+#             */
/*   Updated: 2017/07/13 15:18:17 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		display(t_option *option, t_list *path, \
		int directory, char *path_files)
{
	t_list	*files;

	option->total = 0;
	files = sort(option, path, path_files);
	if (option->l)
		ft_ls_l(option, files, directory, path_files);
	else
		ft_ls_simple(option, files, path_files);
	if (option->upper_r)
		ft_ls_recursif(option, files, path_files);
}

void		ft_manque_de_place(t_option *option, t_list *directory)
{
	(option->multi) ?
		ft_putendl(ft_strjoin(directory->content, ":")) : 0;
}

void		ft_ls_directory(t_option *option, t_list *directory, int wrong)
{
	DIR				*dir;
	t_list			*file_inside;
	struct dirent	*file;
	char			*path_files;

	file = NULL;
	while (directory)
	{
		file_inside = NULL;
		dir = opendir(directory->content);
		while ((file = readdir(dir)))
			ft_lstpushback(&file_inside, file->d_name, \
					ft_strlen(file->d_name) + 1);
		closedir(dir);
		path_files = ft_strjoin(directory->content, "/");
		if (file_inside)
		{
			(wrong == 1) ? ft_putchar('\n') : NULL;
			ft_manque_de_place(option, directory);
			wrong = 1;
			display(option, file_inside, 1, path_files);
		}
		directory = directory->next;
	}
	ft_strdel(&path_files);
}

void		file_or_directory(t_option *option, t_list *file, t_list *directory)
{
	if (file)
		display(option, file, 0, "");
	if (file && directory)
		ft_putchar('\n');
	if (directory)
		ft_ls_directory(option, directory, 0);
}

void		ft_ls(t_option *option, t_list *path)
{
	DIR			*dir;
	t_list		*file;
	t_list		*directory;
	struct stat	sb;

	file = NULL;
	directory = NULL;
	while (path)
	{
		lstat(path->content, &sb);
		if (!(dir = opendir(path->content)) || \
				(S_ISLNK(sb.st_mode) && option->l))
			(errno == ENOTDIR || S_ISLNK(sb.st_mode)) ?
				ft_lstpushback(&file, path->content, path->content_size) :
				ft_error(path->content, 0);
		else
		{
			ft_lstpushback(&directory, path->content, path->content_size);
			(closedir(dir) == -1) ? ft_error(path->content, 0) : NULL;
		}
		path = path->next;
	}
	file_or_directory(option, file, directory);
}
