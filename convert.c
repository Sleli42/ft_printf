/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/14 09:30:24 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	convert_int(va_list arg, t_infos *lst)
{
	long long int	integer;
	t_infos	*tmp;

	integer = va_arg(arg, long long int);
	tmp = lst;
	if (tmp->flag != NULL)
	{
		if (is_modifier(tmp->modifier[0]) != 1)
		{
			if (ft_strlen(ft_itoa_long(integer)) >= 10)
			{
				integer = -1;
				find_flag_int(tmp->flag, integer, tmp);
			}
			else
				find_flag_int(tmp->flag, integer, tmp);
		}
		else
			find_flag_int(tmp->flag, integer, tmp);
	}
	else
		ft_putnbr(integer);
}
