/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbero <rbarbero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:33:59 by rbarbero          #+#    #+#             */
/*   Updated: 2017/11/24 16:18:40 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define GRID_SIZE 104

typedef struct	s_tetri
{
	char			**scheme;
	unsigned char	row;
	unsigned char	col;
	char			letter;
}				t_tetri;

typedef struct	s_grid
{
	unsigned char	size;
	char			**tab;
	int				index_tetri;
}				t_grid;

typedef struct	s_coord
{
	unsigned char	x;
	unsigned char	y;
}				t_coord;

unsigned char	print_usage(void);
unsigned char	print_error(void);

void			print_result(t_grid *result);
char			*ft_read(char *filename);
int				valid_line_check(char **tab, int a, int c);
int				last_check(char**tab, int a, int b, int c);
char			check_error(char *tetriminos);
t_tetri			**parse(const char *input, unsigned char *nb_tetri);
t_grid			*resolve(t_tetri **tetris, unsigned char nb_tetri);

#endif
