/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 13:29:01 by vmartins          #+#    #+#             */
/*   Updated: 2017/07/19 14:42:51 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int  add_option(t_option **option, char c)
{
	t_option	*temp;

	temp = *option;
	if (c == 'l')
		temp->l = 1;
	else if (temp->l != 1)
		temp->l = 0;
	if (c == 'r')
		temp->r = 1;
	else if (temp->r != 1)
		temp->r = 0;
	if (c == 'R')
		temp->upper_r = 1;
	else if (temp->upper_r != 1)
		temp->upper_r = 0;
	if (c == 'a')
		temp->a = 1;
	else if (temp->a != 1)
		temp->a = 0;
	if (c == 't')
		temp->t = 1;
	else if (temp->t != 1)
		temp->t = 0;
	return (0);
}

int		is_option(char *str)
{
	if (*str && *str == '-' && str[1])
		return (1);
	return (0);
}

int		find_option(t_option **option, char *argv, char *str)
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(str, argv[i]))
			add_option(option, argv[i]);
		else
		{
			ft_putstr_fd("ft_ls: illegal option --", 2);
			ft_putchar_fd(argv[i], 2);
			ft_putstr_fd("\nusage: ft_ls [-lrRat] [file, directory...]\n", 2);
			return (0);
		}
	}
	return (1);
}

int		find_params(char **argv, int argc, t_option **option, t_list **path)
{
	int		i;
	int		wrong;

	i = -1;
	wrong = 0;
	while (++i < argc)
	{
		if (is_option(argv[i + 1]) && wrong == 0)
		{
			if (!find_option(option, argv[i + 1], "lrRat"))
				return (0);
		}
		else
		{
			ft_lstpushback(path, argv[i + 1], ft_strlen(argv[i + 1]));
			wrong = 1;
		}
	}
	*path = sort(*option, *path, "Hi");
	return (1);
}

int			main(int argc, char **argv)
{
	t_option	*option;
	t_list		*path;

	path = NULL;
	option = (t_option *)malloc(sizeof(t_option));
	if (argc > 1)
		if(!(find_params(argv, argc - 1, &option, &path)))
			return (0);
	if (!path)
		path = ft_lstnew(".", 1);
	option->multi = (path->next) ? 1 : 0;
	ft_ls(option, path);
	ft_lstdel(&path, ft_del);
	free(option);
	return (0);
}
