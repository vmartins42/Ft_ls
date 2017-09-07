/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:26:11 by vmartins          #+#    #+#             */
/*   Updated: 2016/12/01 14:34:54 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char*)malloc(sizeof(*tab) * len + 1)))
		return (NULL);
	while (len > 0)
	{
		tab[j] = s[i];
		j++;
		i++;
		len--;
	}
	tab[j] = '\0';
	return (tab);
}
