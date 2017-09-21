/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:20:09 by vmartins          #+#    #+#             */
/*   Updated: 2017/09/21 16:28:36 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			**list_to_tab(t_list *list, int *len)
{
	t_list		*files;
	char		**tab;

	*len = 0;
	tab = NULL;
	files = list;
	while (files)
	{
		*len = *len + 1;
		files = files->next;
	}
	files = list;
	if (!(tab = (char **)malloc(sizeof(char *) * (*len) + 1)))
		return (NULL);
	tab[*len] = NULL;
	*len = 0;
	while (files)
	{
		tab[*len] = files->content;
		files = files->next;
		*len = *len + 1;
	}
	return (tab);
}

t_list			*tab_to_list(t_option *option, char **tab, int len)
{
	t_list		*files;
	int			i;

	files = NULL;
	i = 0;
	if (option->r == 1)
	{
		len--;
		while (len >= 0)
		{
			ft_lstpushback(&files, tab[len], ft_strlen(tab[len]) + 1);
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			ft_lstpushback(&files, tab[i], ft_strlen(tab[i]) + 1);
			i++;
		}
	}
	return (files);
}

int				sort_time(char *str, char *str2, char *path_files)
{
	struct stat		sb;
	struct stat		sv;
	char			*path_and_file;
	char			*path_and_file2;

	path_and_file = ft_strjoin(path_files, str);
	path_and_file2 = ft_strjoin(path_files, str2);
	lstat(path_and_file, &sb);
	lstat(path_and_file2, &sv);
	ft_strdel(&path_and_file);
	ft_strdel(&path_and_file2);
	return (sb.st_mtime < sv.st_mtime);
}

static void		ft_sort_test(t_list *files, char *path_files)
{
	t_list		*tmp;
	t_list		*tmp2;
	int			len;

	len = ft_count_lst(files);
	tmp2 = files;
	while (len)
	{
		files = tmp2;
		while (files)
		{
			if (files->next && sort_time(files->content,\
						files->next->content, path_files))
			{
				tmp = files->content;
				files->content = files->next->content;
				files->next->content = tmp;
			}
			files = files->next;
		}
		len--;
	}
}

t_list			*sort(t_option *option, t_list *list, char *path_files)
{
	t_list		*files;
	t_list		*temp;
	char		**tab;
	int			len;
	int			lentab;

	len = 0;
	files = list;
	if (option->t == 1 && ft_strcmp(path_files, "Hi"))
		ft_sort_test(files, path_files);
	tab = list_to_tab(files, &len);
	if (option->t != 1)
		quicksort(tab, len - 1);
	lentab = ft_tablen(tab);
	if (lentab == 2)
		ft_tri(tab);
	temp = tab_to_list(option, tab, len);
	free(tab);
	return (temp);
}
