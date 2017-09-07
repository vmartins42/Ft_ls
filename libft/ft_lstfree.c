/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:00:45 by vmartins          #+#    #+#             */
/*   Updated: 2017/06/20 14:12:32 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *list)
{
	t_list		*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
		tmp = NULL;
	}
}
