/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:09:22 by sderet            #+#    #+#             */
/*   Updated: 2017/11/20 15:51:00 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	nb_blocks_check(char *tetriminos)
{
}

static int	size_check(char *tetriminos)
{
}

static int	char_check(char *tetriminos)
{
}

static int	valid_tetri_check(char *tetriminos)
{
}

int			error_checker(char *tetriminos)
{
	int	(*tests[4])(char *tetriminos);
	int	a;

	a = 0;
	test[0] = &nb_blocks_check;
	test[1] = &size_check;
	test[2] = &char_check;
	test[3] = &valid_tetri_check;
	while (a <= 3)
	{
		if (test(tetriminos) == ERROR)
			return (ERROR);
		a++;
	}
	return (0);
}
