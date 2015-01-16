/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/16 13:09:49 by lubaujar         ###   ########.fr       */
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
	if (integer >= -2147483647 && integer <= 2147483647)
		integer = (int)integer;
	ret = ft_itoa_long(integer);
	if (is_flag(tmp->flag[0]) == 1)
		ret = add_flag(ret ,tmp->flag[0]);
	if (tmp->precision != 0)
	{
		ret = add_precision(ret, (unsigned int)tmp->precision);
		if (tmp->width != 0 && tmp->width > tmp->precision && tmp->flag[0] != '-')
			ret = add_width(ret, (unsigned int)tmp->width, tmp->flag, tmp->precision);
		else if (tmp->width != 0 && tmp->width > tmp->precision && tmp->flag[0] == '-')
			ret = add_width_less(ret, (unsigned int)tmp->width);
		if (tmp->flag[0] == ' ' && ret[0] != '-' && ret[0] != '+')
			ret = add_flag_space(ret);
		ft_putstr(ret);
		return ;
	}
	if (tmp->width != 0)
		ret = add_width(ret, (unsigned int)tmp->width, tmp->flag, tmp->precision);
	if (tmp->flag[0] == ' ' && ret[0] != '-' && ret[0] != '+')
		ret = add_flag_space(ret);
	ft_putstr(ret);
	free(ret);
}

void	convert_string(va_list arg, t_infos *lst)
{
	char	*string;
	t_infos	*tmp;

	string = va_arg(arg, char *);
	tmp = lst;
//	if (tmp->modifier[0] == 'l')
	if (tmp->precision != 0)
		string = add_precision_string(string, tmp->precision);
	if (tmp->width != 0)
		string = add_width_string(string, tmp->width, tmp->flag);
	ft_putstr(string);
}

void	convert_char(va_list arg, t_infos *lst)
{
	int	s;
	
	s = va_arg(arg, int);
	if (s >= 0 && s <= 255)
		ft_putchar((char)s);
}
