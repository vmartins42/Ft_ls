/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:01:07 by vmartins          #+#    #+#             */
/*   Updated: 2017/07/20 14:12:50 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_tri(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strcmp(tab[i], tab[i + 1]) > 0)
	{
		tmp = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = tmp;
	}
}

void		quicksort(char **tab, int size)
{
	char		*pivot;
	char		*temp;
	int			lower;
	int			upper;

	if (size < 2)
		return ;
	lower = 0;
	upper = size - 1;
	pivot = tab[upper];
	while (lower < upper)
	{
		while (ft_strcmp(tab[lower], pivot) < 0)
			lower++;
		while (ft_strcmp(tab[upper], pivot) > 0)
			upper--;
		temp = tab[lower];
		tab[lower] = tab[upper];
		tab[upper] = temp;
	}
	quicksort(tab, lower);
	quicksort(&tab[lower + 1], size - lower - 1);
}
