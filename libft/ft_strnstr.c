/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:48:12 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/30 17:08:42 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (i < len && s1[i])
	{
		while (s1[i + j] == s2[j] && i + j < len && s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char*)s1 + i);
		j = 0;
		i++;
	}
	return (NULL);
}
