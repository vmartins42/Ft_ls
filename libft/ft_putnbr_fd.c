/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:52:06 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/29 16:00:10 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		nb;

	nb = n;
	if (n <= -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n > -2147483648 && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
		else
			ft_putchar_fd(nb + '0', fd);
	}
}
