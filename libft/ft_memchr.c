/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:58:30 by vmartins          #+#    #+#             */
/*   Updated: 2016/12/03 15:57:40 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*src;

	i = 0;
	src = (char*)s;
	while (i != n)
	{
		if ((unsigned char)src[i] == (unsigned char)c)
			return ((char*)s + i);
		i++;
	}
	return (0);
}
