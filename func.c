/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/27 01:52:48 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/01/22 10:38:33 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	detect_infos(char *cpy, int caract, t_infos *new)
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

int		define_convert(t_infos *lst, va_list arg)
{
	t_infos	*tmp;
	int		val;

	tmp = lst;
	val = 0;
	if (is_int(tmp->type) == 1 || tmp->type == 'D')
		val = convert_int(arg, tmp);
	if ((tmp->type) == 's')
		val = convert_string(arg, tmp);
	if (tmp->type == 'c')
		val = convert_char(arg, tmp);
	if (tmp->type == 'C')
		val = convert_wchar(arg, tmp);
	if (tmp->type == 'x' || tmp->type == 'X')
		val = convert_hex(arg, tmp);
	if (tmp->type == 'u' || tmp->type == 'U')
		val = convert_unsigned(arg, tmp);
		convert_char(arg, tmp);
	if (tmp->type == 'C')
		convert_wchar(arg, tmp);
	if (tmp->type == 'x' || tmp->type == 'X')
		convert_hex(arg, tmp);
	if (tmp->type == 'u' || tmp->type == 'U')
		convert_unsigned(arg, tmp);
	if (tmp->type == 'o' || tmp->type == 'O')
		val = convert_octal(arg, tmp);
	if (tmp->type == 'p')
		val = convert_pointer(arg, tmp);
	if (tmp->type == 0)
		return (0);
	return (val);
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
