/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:15:20 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/24 14:46:08 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ch1;
	unsigned char	*ch2;

	i = 0;
	ch1 = (unsigned char*)s1;
	ch2 = (unsigned char*)s2;
	while (i < n)
	{
		if (ch1[i] < ch2[i] || ch1[i] > ch2[i])
			return (ch1[i] - ch2[i]);
		i++;
	}
	return (0);
}
