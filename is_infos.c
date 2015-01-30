/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:55:52 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/30 03:51:29 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		is_flag(char c)
{
	if ((c == '-') || (c == '+') || ((int)c == 32)
			|| (c == '#') || (c == '0'))
		return (1);
	return (0);
}

int		is_modif(char c)
{
	if ((c == 'l') || (c == 'j') || (c == 'z')
			|| (c == 'h'))
		return (1);
	return (0);
}

int		is_conv(char c)
{
	if ((c == 's') || (c == 'S') || (c == 'c') || (c == 'C')
			|| (c == 'x') || (c == 'X') || (c == 'u') || (c == 'U')
			|| (c == 'o') || (c == 'O') || (c == 'd') || (c == 'D')
			|| (c == 'i') || (c == 'p'))
		return (1);
	return (0);
}