/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:09:28 by vmartins          #+#    #+#             */
/*   Updated: 2017/03/14 14:24:49 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabcreate(char *content)
{
	char	**new;
	int		i;

	i = 0;
	if (!(new = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	new[i] = ft_strdup(content);
	new[++i] = NULL;
	return (new);
}
