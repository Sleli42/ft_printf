/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/03 06:05:21 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	convert_int(va_list arg, t_infos *lst)
{
	int		integer;
	int		i;
	int		witdh;
	t_infos	*tmp;

	witdh = 0;
	integer = va_arg(arg, int);
	tmp = lst;
	if (tmp->flag != NULL)
		find_flag(tmp->flag, integer);
	ft_putnbr(integer);
}
