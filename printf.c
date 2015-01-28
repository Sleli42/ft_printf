/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/28 05:26:11 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list	arg;
	int		return_value;
	t_infos	*new;

	new = NULL;
	va_start(arg, rfmt);
	return_value = 0;
	while (*rfmt)
	{
		if (*rfmt == '%')
		{
			if (*rfmt + 1 == '%')
			{
				ft_putchar('%');
				*rfmt++;
			}
			new = (t_infos *)malloc(sizeof(t_infos));
			detect_infos((char*)rfmt, *rfmt, new);
			return_value += define_convert(arg, new);
			while (*rfmt != new->conv)
				*rfmt++;
		}
		else
			ft_putchar(*rfmt);
		*rfmt++;
	}
	va_end(arg);
	return (0);
}

void	detect_infos(char *s, int c, t_infos *infos)
{
	t_infos	*tmp;

	tmp = infos;
	tmp->flag = search_flag(s);
	tmp->width = search_width(s);
	tmp->prec = search_prec(s);
	tmp->modif = search_modif(s);
	tmp->conv = search_conv(s);
}

int		define_convert(va_list arg, t_infos *infos)
{
	t_infos	*tmp;
	int		val;

	tmp = infos;
	val = 0;
	if (tmp->conv == 'd' || tmp->conv == 'i' || tmp->conv == 'D')
		val = convert_int(arg, tmp);
	if (tmp->conv == 's')
		val = convert_string(arg, tmp);
	if (tmp->conv == 'p')
		val = convert_pointer(arg, tmp);
	return (val);
}
