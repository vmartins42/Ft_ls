/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:11:54 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/28 11:35:05 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
