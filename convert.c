/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/27 01:52:27 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/01/22 12:52:50 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		convert_int(va_list arg, t_infos *lst)
{
	long long int	integer;
	char			*ret;
	t_infos	*tmp;

	integer = va_arg(arg, long long int);
	tmp = lst;
	if (tmp->modifier[0] == 'h' && tmp->type != 'D')
		integer = (short)integer;
	if (tmp->modifier[0] == 'h' && tmp->type == 'D'
			|| (tmp->modifier[0] == 'h' && tmp->modifier[1] == 'h' && tmp->type == 'D'))
	{
		integer = (unsigned short)integer;
		ret = ft_uitoa(integer);
	}
	if (tmp->modifier[0] == 'h' && tmp->modifier[1] == 'h' && is_int(tmp->type) == 1)
		integer = (char)integer;
	if (tmp->modifier[0] != 'h' && tmp->modifier[0] != 'l' && tmp->type != 'D' && tmp->modifier[0] != 'j' && tmp->modifier[0] != 'z')

	if (tmp->modifier[0] == 'h')
		integer = (short int)integer;
	if (tmp->modifier[0] != 'h' && tmp->modifier[0] != 'l' && tmp->type != 'D')
	{
		integer = (int)integer;
		ret = ft_itoa(integer);
	}
	if (tmp->type == 'j')
		ret = ft_itoa_long(integer);
	else
		ret = ft_itoa_long(integer);
	if (is_flag(tmp->flag[0]) == 1)
		ret = add_flag(ret ,tmp->flag[0]);
	if (tmp->precision != 0 && tmp->precision > ft_strlen(ret))
	{
		ret = add_precision(ret, (unsigned int)tmp->precision);
		if (tmp->width != 0 && tmp->width > tmp->precision && tmp->flag[0] != '-')
			ret = add_width(ret, (unsigned int)tmp->width, tmp->flag, tmp->precision);
		else if (tmp->width != 0 && tmp->width > tmp->precision && tmp->flag[0] == '-')
			ret = add_width_less(ret, (unsigned int)tmp->width);
		if (tmp->flag[0] == ' ' && ret[0] != '-' && ret[0] != '+')
			ret = add_flag_space(ret);
		ft_putstr(ret);
		return (ft_strlen(ret));
	}
	if (tmp->width != 0)
		ret = add_width(ret, (unsigned int)tmp->width, tmp->flag, tmp->precision);
	if (tmp->flag[0] == ' ' && ret[0] != '-' && ret[0] != '+')
		ret = add_flag_space(ret);
	if (ret)
		ft_putstr(ret);
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	return (ft_strlen(ret));
}

int		convert_string(va_list arg, t_infos *lst)
{
	char	*string;
	t_infos	*tmp;
	
	tmp = lst;
	//if (tmp->modifier[0] == 'l')
	//	ft_put_w(arg);
	string = va_arg(arg, char *);
	if (string == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (string == '\0')
		return (0);
	if (ft_strlen(string) == 1)
	{
		ft_putchar(*string);
		return (1);
	}
	if (tmp->precision != 0)
		string = add_precision_string(string, tmp->precision);
	if (tmp->width != 0)
		string = add_width_string(string, tmp->width, tmp->flag);
	ft_putstr(string);
	return (ft_strlen(string));
}

int		convert_char(va_list arg, t_infos *lst)
{
	t_infos			*tmp;
	int				i;
	unsigned int	c;
	char			*ret;
	
	tmp = lst;
	i = 0;
	c = va_arg(arg, unsigned int);
	c = (char)c;
	if (tmp->width != 0)
	{
		ret = (char *)malloc(sizeof(char) * tmp->width + 1);
		while (i < tmp->width)
		{
			if (c >= 0 && c <= 126)
				ret[i] = ' ';
			i++;
		}
		ret[i] = c;
		ft_putstr(ret);
		return (i);
	}
	else
	{
		if (c >= 0 && c <= 126)
			ft_putchar(c);
	}
	return (1);
}

void	convert_wchar(va_list arg, t_infos *lst)
{
	unsigned int	wc;
	char			*wchar_bin;

	wc = va_arg(arg, unsigned int);
	if (wc >= 0 && wc <= 126)
		ft_putchar((char)wc);
/*	else
	else
	{
		wchar_bin = binary_convert(wc);
		//printf("wchar = %s\n", wchar_bin);
		cmp_msk(wchar_bin);
	}*/
}

int		convert_hex(va_list arg, t_infos *lst)
{
	t_infos				*tmp;
	unsigned long int	deci;
	char				*hex;

	tmp = lst;
	deci = va_arg(arg, unsigned long int);
	if (tmp->modifier[0] == 'h')
		deci = (unsigned short)deci;
	if (tmp->modifier[0] == 'h' && tmp->modifier[1] == 'h')
		deci = (unsigned char)deci;
	if (tmp->type == 'X')
		hex = hexa_convert(deci, 1, tmp->flag[0]);
	else
		hex = hexa_convert(deci, 0, tmp->flag[0]);
	ft_putstr(hex);
	return (ft_strlen(hex));
}

int		convert_unsigned(va_list arg, t_infos *lst)
{
	t_infos				*tmp;
	unsigned long int	integer;
	char				*ret;

	tmp = lst;
	integer = va_arg(arg, unsigned long int);
	if (tmp->modifier[0] == 'h' || (tmp->modifier[0] == 'h' 
			&& tmp->modifier[1] == 'h' && tmp->type == 'U'))
	{
		integer = (unsigned short)integer;
		ret = ft_uitoa(integer);
	}
	if (tmp->modifier[0] == 'h' && tmp->modifier[1] == 'h' && tmp->type == 'u')
	{
		integer = (unsigned char)integer;
		ret = ft_uitoa(integer);
	}
	else
		ret = ft_itoa_ulong(integer);
	if (tmp->precision > ft_strlen(ret))
		ret = add_u_precision(ret, tmp->precision);
	if (tmp->width > ft_strlen(ret))
		ret = add_u_width(ret, tmp->width, tmp->flag[0], tmp->precision);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_octal(va_list arg, t_infos *lst)
{
	t_infos				*tmp;
	unsigned long int	integer;
	char				*ret;
	int					i;

	tmp = lst;
	integer = va_arg(arg, unsigned long int);
	i = 6;
	if (tmp->modifier[0] == 'h')
		integer = (unsigned short)integer;
	if (tmp->modifier[0] == 'h' && tmp->modifier[1] == 'h' && tmp->type == 'O')
		integer = (signed char)integer;
	else if (tmp->modifier[0] == 'h' && tmp->modifier[1] == 'h' && tmp->type == 'o')
		integer = (unsigned char)integer;
/*	if (tmp->modifier[0] == 'h' && tmp->modifier[1] == 'h' && tmp->type == 'O')
	{
		integer = (unsigned short)integer;
		printf("integer[1]: %u\n", integer);
	}*/
	if (tmp->modifier[0] == 'h' && tmp->modifier[1] == 'h' && tmp->type == 'O')
	{
		ret = octal_convert(integer, tmp->flag[0]);
		ret[i] = '\0';
	}
	else
		ret = octal_convert(integer, tmp->flag[0]);
	if (tmp->precision > ft_strlen(ret))
		ret = add_o_precision(ret, tmp->precision);
	if (tmp->width > ft_strlen(ret))
		ret = add_o_width(ret, tmp->width, tmp->flag[0], tmp->precision);
	if (ret)
	{
		ft_putstr(ret);
		return (ft_strlen(ret));
	}
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	return (0);
}

int		convert_pointer(va_list arg, t_infos *lst)
{
	t_infos			*tmp;
	unsigned long int	addr;
	char			*ret;
	char			*temp;
	int				i;

	tmp = lst;
	addr = va_arg(arg, unsigned long int);
	temp = hexa_convert((unsigned long int)addr, 0, tmp->flag[0]);
	ret = add_0x_addr(temp, 0, tmp->precision, tmp->width);
	if (tmp->flag[0] == '-')
	{
		if (ret[2] == '7')
			ft_putstr(ret);
		else
		{
			temp = ft_strrev(ret);
			ft_putstr(temp);
		}
	}
	else
		ft_putstr(ret);
	return (ft_strlen(ret));
}
