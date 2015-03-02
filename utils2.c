/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 05:26:34 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 06:15:03 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*define_modif_int(t_infos *infos, long long int integer)
{
	char	*ret;

	if (is_modif(infos->modif[0]) == 0 && (infos->conv == 'd'
				|| infos->conv == 'i'))
	{
		integer = (int)integer;
		ret = ft_itoa(integer);
	}
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h' && (infos->conv == 'd'
					|| infos->conv == 'i'))
			integer = (signed char)integer;
		else
		{
			if (infos->conv == 'D')
				integer = (unsigned short)integer;
			else
				integer = (short)integer;
		}
		ret = ft_itoa(integer);
	}
	if (infos->modif[0] == 'l' && infos->modif[1] != 'l')
		ret = ft_itoa_long(integer);
	if (infos->conv == 'D' || infos->modif[1] == 'l'
			|| infos->modif[0] == 'j' || infos->modif[0] == 'z')
		ret = ft_itoa_long(integer);
	return (ret);
}
