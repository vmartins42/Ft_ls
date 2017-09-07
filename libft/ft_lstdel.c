/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 09:37:26 by vmartins          #+#    #+#             */
/*   Updated: 2017/06/26 09:42:07 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*list_temp;

	list = *alst;
	while (list)
	{
		list_temp = list->next;
		del(list->content, list->content_size);
		free(list);
		list = list_temp;
	}
	*alst = NULL;
}
