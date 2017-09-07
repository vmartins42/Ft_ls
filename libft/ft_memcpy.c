/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:09:05 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/24 15:56:46 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *source;
	char *desti;

	source = (char*)src;
	desti = (char*)dest;
	while (n)
	{
		n--;
		desti[n] = source[n];
	}
	return (desti);
}
