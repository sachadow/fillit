/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:35:18 by sderet            #+#    #+#             */
/*   Updated: 2017/11/20 15:45:28 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	err_argnbr(void)
{
	ft_putendl("usage: ./fillit source_tetriminos");
}

void	err_standard(void)
{
	ft_putendl("error");
}
