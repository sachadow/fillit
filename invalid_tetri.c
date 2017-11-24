/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:09:22 by sderet            #+#    #+#             */
/*   Updated: 2017/11/24 16:18:22 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

/*
**	Checks if every line in the file is 4 characters long, or 1 character
**	long if it is the space between two tetriminos.
**	Returns 0 if the file works, 1 else.
*/

static char	size_check(char *tet)
{
	int a;
	int b;
	int c;

	a = 0;
	c = 0;
	while (tet[a] != '\0')
	{
		b = 0;
		while (b < 4)
		{
			if (tet[a + b] != '#' && tet[a + b] != '.')
				return (1);
			b++;
		}
		c++;
		if (tet[a + b] != '\n' || c > 4 || (tet[a + b + 1] == '\n' && c != 4))
			return (1);
		if (tet[a + b + 1] == '\n')
			c = 0;
		a += (tet[a + b + 1] == '\n' ? b + 2 : b + 1);
	}
	if (c != 4)
		return (1);
	return (0);
}

/*
**	Checks if each tetriminos has 4 #. If not, returns 1.
*/

static char	nb_blocks_check(char *tet)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	while (tet[a] != '\0')
	{
		if (tet[a] == '\n')
			c++;
		if (tet[a] == '#')
			b++;
		else if (tet[a] == '\n' && (tet[a + 1] == '\n' || tet[a + 1] == '\0'))
		{
			if (b != 4)
				return (1);
			b = 0;
		}
		a++;
	}
	if (c < 4)
		return (1);
	return (0);
}

/*
**	Checks if every character in the file is either a ., a # or a \n.
**	If not, returns 1.
*/

static char	char_check(char *tet)
{
	int a;

	a = 0;
	while (tet[a] != '\0')
	{
		if (tet[a] != '.' && tet[a] != '#' && tet[a] != '\n')
			return (1);
		a++;
	}
	return (0);
}

/*
**	Checks if each # in each tetriminos has at least one adjacent #.
**	If not, returns 1.
*/

static char	valid_tetri_check(char *tet)
{
	int		a;
	int		b;
	int		c;
	char	**tab;

	a = 0;
	tab = ft_strsplit(tet, '\n');
	while (tab[a] != 0)
	{
		c = 0;
		while (c < 4)
		{
			b = valid_line_check(tab, a, c);
			if (b == 1)
				return (1);
			c++;
		}
		a += 4;
	}
	if (last_check(tab, 0, -1, -1) == 1)
		return (1);
	return (0);
}

/*
**	Uses the other functions in the file to check for any error.
**	If any error is detected, returns 0.
*/

char		check_error(char *tetriminos)
{
	char	(*test[4])(char *tetriminos);
	int		a;

	a = 0;
	test[0] = &size_check;
	test[1] = &nb_blocks_check;
	test[2] = &char_check;
	test[3] = &valid_tetri_check;
	while (a <= 3)
	{
		if (test[a](tetriminos) == 1)
			return (0);
		a++;
	}
	return (1);
}
