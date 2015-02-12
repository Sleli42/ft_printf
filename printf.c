/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/12 17:48:01 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list arg;

	va_start(arg, rfmt);
	//i -= initConv((char *)rfmt, j);
	//i += write(1, &(rfmt[j]), 1);
	i = checkString((char *)rfmt, arg);
	va_end(arg);
	return (i);
}

int		checkString(char *s, va_list arg)
{
	int		i;

	i = 0;
	while (*s)
	{
		/* *(s + 1) || *(s + 2) ...*/
		w
	}
}

int		initConv(char *s, int c)
{
	t_infos *new;
	int		ret;

	ret = 0;
	new = (t_infos *)malloc(sizeof(t_infos));
	ret = detect_infos(s, c, new);
	printf("c entry: |%c|", s[c]);
	return (ret);
}
/*
int		ft_printf(const char *rfmt, ...)
{
	va_list	arg;
	int		return_value;
	//int		i;
	int		j;
	int		tmp;
	t_infos	*new;

	new = NULL;
	va_start(arg, rfmt);
	//i = 0;
	j = 0;
	tmp = 0;
	return_value = 0;
	while (rfmt[j])
	{
		if (rfmt[j] == '%' && rfmt[j + 1] != '%')
		{
			if (rfmt[j + 1] == '\0')
				return (0);
			new = (t_infos *)malloc(sizeof(t_infos));
			tmp = detect_infos((char*)rfmt, j, new);
			//printf("rfmt[j]: |%c|\n", rfmt[j]);
			return_value += define_convert(arg, new);
			//printf("conv: |%c|\n", new->conv);
			if (new->conv == 'B')
			{
				tmp = j + noConv((char *)rfmt, new);
				if (nextPercent((char *)rfmt, j) == 1)
				{
					ft_putchar('%');
					j++;
					return_value++;
				}
				while (j < tmp)
					j++;
				ft_putchar(rfmt[j]);
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
*/
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
//	printf("flags: |%s|\n", tmp->flag);
	tmp->width = search_width(s, c);
	if (tmp->width >= 0)
		i += ft_strlen(ft_itoa(tmp->width));
	//printf("i: %d\n", i);
	//printf("width: |%d|\n", tmp->width);
	tmp->prec = search_prec(s, c);
	if (tmp->prec >= 0)
		i += ft_strlen(ft_itoa(tmp->prec));
	//printf("i: %d\n", i);
//	printf("prec: |%d|\n", tmp->prec);
	tmp->modif = search_modif(s, c);
	if (tmp->modif[0] != '\0')
		i += ft_strlen(tmp->modif);
	//printf("i: %d\n", i);
	//printf("modif: |%s|\n", tmp->modif);
	tmp->conv = search_conv(s, c);
	if (tmp->conv != 'B')
		i += 1;
	//printf("i: %d\n", i);
//	printf("conv: |%c|\n", tmp->conv);
	return (i);
//	printf("conv: |%c|\n", tmp->conv);
//	printf("conv find: %c\n", tmp->conv);
}

int		define_convert(va_list arg, t_infos *infos)
{
	t_infos	*tmp;
	int		val;

	tmp = infos;
	val = 0;
	if (tmp->conv == 'd' || tmp->conv == 'i')
		val = convert_int(arg, tmp);
	if (tmp->conv == 'D')
		val = convert_long_int(arg, tmp);
	if (tmp->conv == 's')
		val = convert_string(arg, tmp);
	if (tmp->conv == 'p')
		val = convert_pointer(arg, tmp);
	if (tmp->conv == 'c')
		val = convert_char(arg, tmp);
	if (tmp->conv == 'C')
		val = convert_wchar(arg, tmp);
	if (tmp->conv == 'S')
		val = convert_wchar_string(arg, tmp);
	if (tmp->conv == 'u' || tmp->conv == 'U')
		val = convert_unsigned(arg, tmp);
	if (tmp->conv == 'o' || tmp->conv == 'O')
		val = convert_octal(arg, tmp);
	if (tmp->conv == 'x' || tmp->conv == 'X')
		val = convert_hexa(arg, tmp);
	return (val);
}
