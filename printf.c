/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/03 21:07:04 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list	arg;
	int		return_value;
	int		i;
	int		j;
	int		tmp;
	t_infos	*new;

	new = NULL;
	va_start(arg, rfmt);
	i = 0;
	j = 0;
	tmp = 0;
	return_value = 0;
	while (rfmt[j])
	{
		if (rfmt[j] == '%' && rfmt[j + 1] != '%')
		{
			new = (t_infos *)malloc(sizeof(t_infos));
			tmp = detect_infos((char*)rfmt, j, new);
			//printf("rfmt[j]: |%c|\n", rfmt[j]);
			return_value += define_convert(arg, new);
			if (new->conv == 'B')
			{
				while (rfmt[j + 1] == ' ')
					j++;
				if (rfmt[j + 1] == '%')
				{
					ft_putchar('%');
					j = j + 1;
					return_value = return_value + 1;
				}
				if (new->width > 0)
				{
					//printf("|%c|\n", new->flag[0]);
					if (new->flag[0] == '-')
					{
						ft_putchar(rfmt[j + tmp]);
						j++;
						return_value++;
						while (++i < new->width)
						{
							ft_putchar(' ');
							return_value++;
						}
					}
					else
					{
						tmp = tmp + 1;
						while (++i < new->width)
						{
							if (rfmt[j] >= '0' && rfmt[j] <= '9')
								j++;
							if (new->flag[0] == '0')
								ft_putchar('0');
							else
								ft_putchar(' ');
							return_value++;
						}
					}
				}
				while (--tmp > 0)
					j++;
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
			return_value = return_value + 1;
		}
		j++;
	}
	free(new);
	va_end(arg);
	return (return_value);
}

int		detect_infos(char *s, int c, t_infos *infos)
{
	t_infos	*tmp;
	int		i;
/* a refaire */
	tmp = infos;
	i = 0;
	tmp->flag = search_flag(s, c);
	if (tmp->flag[0] != '\0')
		i += ft_strlen(tmp->flag);
	//printf("i: %d\n", i);
	//printf("flags: |%s|\n", tmp->flag);
	tmp->width = search_width(s, c);
	if (tmp->width != 0)
		i += ft_strlen(ft_itoa(tmp->width));
	//printf("i: %d\n", i);
	//printf("width: |%d|\n", tmp->width);
	tmp->prec = search_prec(s, c);
	if (tmp->prec != 0)
		i += ft_strlen(ft_itoa(tmp->prec));
	//printf("i: %d\n", i);
	//printf("prec: |%d|\n", tmp->prec);
	tmp->modif = search_modif(s, c);
	if (tmp->modif[0] != '\0')
		i += ft_strlen(tmp->modif);
	//printf("i: %d\n", i);
	//printf("modif: |%s|\n", tmp->modif);
	tmp->conv = search_conv(s, c);
	if (tmp->conv != 'B')
		i += 1;
	//printf("i: %d\n", i);
	//printf("conv: |%c|\n", tmp->conv);
	return (i);
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
