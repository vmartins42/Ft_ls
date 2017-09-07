/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:58:45 by vmartins          #+#    #+#             */
/*   Updated: 2017/07/25 11:47:32 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_option
{
	int		l;
	int		r;
	int		upper_r;
	int		a;
	int		t;
	int		link;
	size_t	user;
	size_t	group;
	int		size;
	int		min;
	int		maj;
	int		len_min;
	int		len_maj;
	int		total;
	int		multi;
}				t_option;

int				ft_count_lst(t_list *list);
void			ft_ls(t_option *option, t_list *path);
void			ft_error(char *file, int error);
void			display(t_option *option, t_list *path, int directory, \
		char *path_files);
void			ft_ls_l(t_option *option, t_list *list, int directory, \
		char *path_files);
void			ft_ls_simple(t_option *option, t_list *list, char *path_files);
void			ft_ls_recursif(t_option *option, t_list *list, \
		char *path_files);
void			stock_size(t_option *option, t_list *list, char *path_files);
char			*ft_link(t_option *option, char *str);
t_list			*sort(t_option *option, t_list *list, char *path_files);
void			quicksort(char **tab, int size);
int				sort_time(char *str, char *str2, char *path_files);
void			print_min_and_maj(t_option *option, struct stat *sb);
void			get_link(char *file, mode_t mode);
void			print_ft_ls_ls(t_option *option, char *file, char *path_files, \
		struct stat *sb);
void			print_link(t_option *option, mode_t mode);
void			print_rights(mode_t mode);
void			print_type(mode_t mode);
void			print_size(t_option *option, mode_t mode);
void			print_date_modif(time_t date_modif);
int				ft_get_len(int n);
void			print_options(char *str, int size);
void			ft_tri(char **tab);

#endif
