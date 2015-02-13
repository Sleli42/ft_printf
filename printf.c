/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/13 17:53:46 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list arg;
	int		i;

	va_start(arg, rfmt);
	i = 0;
	//i -= initConv((char *)rfmt, j);
	//i += write(1, &(rfmt[j]), 1);
	i = checkString((char *)rfmt, arg);
	va_end(arg);
	return (i);
}

int		checkString(char *s, va_list arg)
{
	int		i;
	int		return_val;
	int		tmp;
	t_infos	*new;

	i = 0;
	tmp = 0;
	return_val = 0;
	new = NULL;
	while (s[i])
	{
		if (s[i] == '%')
		{
			new = (t_infos *)malloc(sizeof(t_infos));
			tmp = detect_infos(s, i, new);
			return_val += define_convert(s, arg, new);
		//	printf("ret: %d\n", return_val);
			if (new->conv != 'B')
			{
				while (s[i] != new->conv)
					i++;
				if (s[i + 1] == '\0')
					return (return_val);
			}
			else
				while (tmp-- >= 0)
					i++;
		}
		return_val += write(1, &(s[i]), 1);
		i++;
		//printf("**ret: %d\n", return_val);
	}
	free(new);
//	printf("***ret: %d\n", return_val);
	return (return_val);
}

int		detect_infos(char *s, int c, t_infos *new)
{
	int		i;

	i = 0;
	new->flag = search_flag(s, c);
	if (new->flag[0] != '\0')
		i += ft_strlen(new->flag);
	new->width = search_width(s, c);
	if (new->width >= 0)
		i += ft_strlen(ft_itoa(new->width));
	new->prec = search_prec(s, c);
	if (new->prec >= 0)
		i += ft_strlen(ft_itoa(new->prec));
	new->modif = search_modif(s, c);
	if (new->modif[0] != '\0')
		i += ft_strlen(new->modif);
	new->conv = search_conv(s, c);
	if (new->conv != 'B')
		i += 1;
	return (i);
}

int		define_convert(char *s, va_list arg, t_infos *infos)
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
	if (tmp->conv == 'B')
		val = noConv(s, tmp);
	return (val);
}
