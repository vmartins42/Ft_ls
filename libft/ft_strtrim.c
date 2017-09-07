/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:41:20 by vmartins          #+#    #+#             */
/*   Updated: 2016/11/29 14:04:26 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*tab;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!(s[i]) || ft_strlen(s) == 0 || !s)
		return (ft_strsub(s, 0, 0));
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if (!(tab = (char*)malloc(sizeof(*tab) * (len - i) + 2)))
		return (NULL);
	while (i < len + 1)
		tab[j++] = s[i++];
	tab[j] = '\0';
	return (tab);
}
