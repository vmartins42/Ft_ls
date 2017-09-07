/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:45:10 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/25 15:15:20 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == c)
			return ((char*)s + i);
		i--;
	}
	if (s[i] == c)
		return ((char*)s + i);
	return (0);
}
