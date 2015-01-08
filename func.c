/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/08 03:11:57 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	detect_infos(char *cpy, int caract, t_infos *new)
{
	int		len;
	t_infos	*tmp;

	tmp = new;
	len = search_flag(cpy, caract, new);
	len = search_width(cpy, len, new);
	len = search_precision(cpy, len, new);
	search_modifier(cpy, caract, new);
	search_converter_types(cpy, caract, new);
	if (tmp->width < 0)
		tmp->width = 0;
	if (tmp->precision < 0 || tmp->precision > 10000)
		tmp->precision = 0;
}

void	define_convert(t_infos *lst, va_list arg)
{
	t_infos	*tmp;

	tmp = lst;
	if (is_int(tmp->type) == 1)
		convert_int(arg, tmp);
}

void	find_flag_int(char *flag, int integer, t_infos *lst)
{
	t_infos	*tmp;
	char	*c_int;
	char	*temp;

	tmp = lst;
	c_int = ft_itoa(integer);
	if (is_modifier(tmp->modifier[0]) == 1)
		c_int = find_modifier(tmp->modifier, integer);
	if (flag[0] == '+')
	{
		if (ft_atoi(c_int) >= 0 && c_int != ft_itoa(integer))
		{
			c_int = recover_int(c_int, tmp->modifier, tmp->precision);
			temp = c_int;
		}
		else if (integer < 0)
			temp = c_int;
		else
			temp = cpy_int_without_sign(c_int);
	}
	else
		temp = c_int;
	if (tmp->precision != 0 && tmp->precision > ft_strlen(c_int))
		temp = add_precision_int(tmp->precision, temp, integer, tmp->modifier);
	if (tmp->width != 0 && tmp->width > tmp->precision || tmp->width != 0)
	{
		temp = add_width_int(tmp->width, temp);
		if (tmp->width - ft_strlen(temp) + 1 == 0)
		{
			ft_putstr(temp);
			return ;
		}
	}
	else if (tmp->width != 0 && tmp->width < tmp->precision)
		ft_putstr(temp);
	ft_putstr(temp);
}

char	*find_modifier(char *modifier, int integer)
{
	char	*ret;

	if (*modifier == 'h')
	{
		ret = convert_int_short(integer);
		return (ret);
	}
	return (modifier);
}
