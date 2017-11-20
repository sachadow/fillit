/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:26:57 by sderet            #+#    #+#             */
/*   Updated: 2017/11/20 15:51:08 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define ERROR 1



/*	file checks 			*/

int		error_checker(char *tetriminos);

/*	error messages			*/

void	err_argnbr(void);
void	err_standard(void);

#endif
