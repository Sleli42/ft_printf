/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/19 17:26:10 by lubaujar         ###   ########.fr       */
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
	if (tmp->flag == NULL)
		tmp->flag = '\0';
}

void	define_convert(t_infos *lst, va_list arg)
{
	t_infos	*tmp;

	tmp = lst;
	if (is_int(tmp->type) == 1)
		convert_int(arg, tmp);
	if ((tmp->type) == 's')
		convert_string(arg, tmp);
	if (tmp->type == 'c')
		convert_char(arg, tmp);
	if (tmp->type == 'x' || tmp->type == 'X')
		convert_hex(arg, tmp);
	if (tmp->type == 'u' || tmp->type == 'u')
		convert_unsigned(arg, tmp);
	if (tmp->type == 'o' || tmp->type == 'O')
		convert_octal(arg, tmp);
	if (tmp->type == 'p')
		convert_pointer(arg, tmp);
}

char	*add_u_precision(char *integer, int precision)
{
	char	*ret;
	int		i;

	ret = ft_strnew(precision);
	i = 0;
	while (i < precision - ft_strlen(integer))
		ret[i++] = '0';
	while (*integer)
		ret[i++] = *integer++;
	return (ret);
}

char	*add_u_width(char *integer, int width, char flag, int precision)
{
	char	*ret;
	int		i;

	ret = ft_strnew(width);
	i = 0;
	if (flag == '-')
	{
		ret = offset_left(integer, width);
		return (ret);
	}
	while (i < width - ft_strlen(integer))
	{
		if (flag == '0' && precision == 0)
			ret[i++] = '0';
		else
			ret[i++] = ' ';
	}
	while (*integer)
		ret[i++] = *integer++;
	return (ret);
}

char	*offset_left(char *integer, int width)
{
	char	*ret;
	int		i;

	i = 0;
	while (*integer)
		ret[i++] = *integer++;
	while (i < width)
		ret[i++] = ' ';
	return (ret);
}
