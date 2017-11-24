/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:35:18 by sderet            #+#    #+#             */
/*   Updated: 2017/11/24 16:22:24 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		valid_line_check(char **tab, int a, int c)
{
	int b;
	int d;

	b = 0;
	d = a + c;
	while (tab[d][b] != '\0')
	{
		if (tab[d][b] == '#')
			if ((c != 3 ? tab[d + 1][b] != '#' : 1) &&
				(c != 0 ? tab[d - 1][b] != '#' : 1) &&
				(b != 0 ? tab[d][b - 1] != '#' : 1) &&
				tab[d][b + 1] != '#')
				return (1);
		b++;
	}
	return (0);
}

int		howmany_adj(char **tab, int a, int b, int c)
{
	return ((c != 3 ? (tab[a + c + 1][b] == '#') : 0) +
		(c != 0 ? (tab[a + c - 1][b] == '#') : 0) +
		(b != 0 ? (tab[a + c][b - 1] == '#') : 0) +
		(tab[a + c][b + 1] == '#'));
}

/*
**	Verifie l'existence d'un # directement a droite ou en dessous
**	de tout diese qui n'est pas le quatrieme de son tetriminos.
*/

int		last_check(char **tab, int a, int b, int c)
{
	int		d;

	while (tab[a] != 0)
	{
		c = -1;
		d = 0;
		while (++c < 4)
		{
			b = -1;
			while (tab[a + c][++b] != '\0')
			{
				if (tab[a + c][b] == '#')
				{
					d += howmany_adj(tab, a, b, c);
				}
			}
		}
		if (d < 5)
			return (1);
		a += 4;
	}
	return (0);
}
