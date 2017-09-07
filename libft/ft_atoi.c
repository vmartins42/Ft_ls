/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:24:17 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/25 17:20:56 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\r'
			|| *nptr == '\v' || *nptr == ' ' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
		sign = (-1);
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		nb *= 10;
		nb += (*nptr - '0');
		nptr++;
	}
	return (nb * sign);
}
