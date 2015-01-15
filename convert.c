/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/15 06:05:54 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	convert_int(va_list arg, t_infos *lst)
{
	long long int	integer;
	char			*ret;
	t_infos	*tmp;

	integer = va_arg(arg, long long int);
	tmp = lst;
	if (tmp->modifier[0] == 'h')
		integer = (short int)integer;
	if (tmp->modifier[0] != 'h' || tmp->modifier[0] != 'l')
		integer = (int)integer;
	ret = ft_itoa(integer);
	if (is_flag(tmp->flag[0]))
		ret = add_flag(ret ,tmp->flag[0]);
	if (tmp->precision != 0)
	{
		ret = add_precision(ret, (unsigned int)tmp->precision);
		if (tmp->width != 0 && tmp->width > tmp->precision)
			ret = add_width(ret, (unsigned int)tmp->width);
		ft_putstr(ret);
		return ;
	}
	if (tmp->width != 0)
		ret = add_width(ret, (unsigned int)tmp->width);
	ft_putstr(ret);
	/*
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
		ft_putnbr(integer);*/
}
