/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:45:19 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/28 11:09:57 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*tab;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(tab = (char*)malloc(sizeof(*tab) * i + 1)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		tab[i] = f(s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
