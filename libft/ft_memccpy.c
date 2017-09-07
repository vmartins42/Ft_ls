/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:41:25 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/29 13:23:13 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*source;
	char	*desti;
	size_t	i;

	i = 0;
	source = (char*)src;
	desti = (char*)dest;
	while (i < n)
	{
		if ((unsigned char)source[i] == (unsigned char)c)
		{
			desti[i] = (unsigned char)source[i];
			return ((char*)desti + (i + 1));
		}
		desti[i] = (unsigned char)source[i];
		i++;
	}
	return (NULL);
}
