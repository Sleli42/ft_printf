/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/30 07:44:39 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list	arg;
	int		return_value;
	int		i;
	int		j;
	t_infos	*new;

	new = NULL;
	va_start(arg, rfmt);
	i = 0;
	j = 0;
	return_value = 0;
	while (rfmt[j])
	{
		if (rfmt[j] == '%' && rfmt[j + 1] != '%')
		{
			new = (t_infos *)malloc(sizeof(t_infos));
			detect_infos((char*)rfmt, j, new);
			return_value += define_convert(arg, new);
			if (new->conv == 'B')
			{
				while (rfmt[j + 1] == ' ')
					j++;
				if (rfmt[j + 1] == '%')
				{
					ft_putchar('%');
					j = j + 1;
					i = i + 1;
				}
			}
			else
			{
				while (rfmt[j] != new->conv)
					j++;
			}
		}
		else
		{
			if ((rfmt[j] == '%' && rfmt[j + 1] == '%'))
			{
				ft_putchar('%');
				j = j + 1;
			}
			else
				ft_putchar(rfmt[j]);
			i++;
		}
		j++;
	}
	free(new);
	va_end(arg);
	return (return_value + (i));
}

void	detect_infos(char *s, int c, t_infos *infos)
{
	t_infos	*tmp;
	int		i;
/* a refaire */
	tmp = infos;
	tmp->flag = search_flag(s, c);
	//printf("flags: |%s|\n", tmp->flag);
	tmp->width = search_width(s, c);
	//printf("width: |%d|\n", tmp->width);
	tmp->prec = search_prec(s, c);
	//printf("prec: |%d|\n", tmp->prec);
	tmp->modif = search_modif(s, c);
	//printf("modif: |%s|\n", tmp->modif);
	tmp->conv = search_conv(s, c);
	//printf("conv: |%c|\n", tmp->conv);
//	printf("conv find: %c\n", tmp->conv);
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
	if (tmp->conv == 'c')
		val = convert_char(arg, tmp);
	if (tmp->conv == 'u' || tmp->conv == 'U')
		val = convert_unsigned(arg, tmp);
	if (tmp->conv == 'o' || tmp->conv == 'O')
		val = convert_octal(arg, tmp);
	if (tmp->conv == 'x' || tmp->conv == 'X')
		val = convert_hexa(arg, tmp);
	return (val);
}
