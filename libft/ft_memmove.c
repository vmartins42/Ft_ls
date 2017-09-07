/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:01:17 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/30 11:58:18 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*desti;
	char	*source;

	i = 0;
	desti = (char*)dest;
	source = (char*)src;
	if (dest < src)
	{
		while (i < n)
		{
			desti[i] = source[i];
			i++;
		}
	}
	else
	{
		while (n)
		{
			n--;
			desti[n] = source[n];
		}
	}
	return (dest);
}
