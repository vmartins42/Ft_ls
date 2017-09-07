/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:21:21 by vmartins          #+#    #+#             */
/*   Updated: 2017/06/21 15:24:08 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_error(char *file, int error)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(file);
	(error) ? exit(EXIT_FAILURE) : 0;
}
