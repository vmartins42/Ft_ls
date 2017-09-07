/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:36:26 by vmartins          #+#    #+#             */
/*   Updated: 2016/12/02 10:57:39 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_mots(const char *s, char c)
{
	int		nb;
	int		i;

	nb = 1;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			nb++;
		i++;
	}
	return (nb);
}

static char	**ft_tab(const char *s, char c, char **tab)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			tab[index] = ft_strsub(s, i, j);
			index++;
			i = i + j;
		}
		else
			i++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb;
	char	**tab;

	if (!s)
		return (0);
	nb = ft_nb_mots(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * nb + 1)))
		return (NULL);
	tab[nb] = 0;
	return (ft_tab(s, c, tab));
}
