/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:33:51 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/03 01:55:30 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_flag(char c)
{
	if ((c == '-') || (c == '+') || (c == ' ')
			|| (c == '#'))
		return (1);
	return (0);
}

int		is_modifier(char c)
{
	if ((c == 'l') || (c == 'j') || (c == 'z')
			|| (c == 'h'))				/* a completer ...[hh, ll]*/
		return (1);
	return (0);
}

int		is_converter_min(char c)
{
	if ((c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'o') || (c == 'u') || (c == 'x') || (c == 'c'))
		return (1);
}

int		is_convert_maj(char c)
{
	if ((c == 'S') || (c == 'D') || (c == 'O') || (c == 'U') || (c == 'x') || (c == 'C'))
			return 1;
}
