/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:02:30 by vmartins          #+#    #+#             */
/*   Updated: 2017/06/27 10:10:07 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_create_str(char *str, int len, int n, int neg)
{
	while (len >= 0)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

static char		*ft_check_overflow(int n)
{
	char	*str;

	str = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		negative;
	int		len;

	len = ft_get_len(n);
	negative = n;
	str = ft_check_overflow(n);
	if (str)
		return (str);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		n *= -1;
	ft_create_str(str, len, n, negative);
	return (str);
}
