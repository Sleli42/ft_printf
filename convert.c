/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 20:42:39 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/24 16:50:18 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/02/20 01:03:17 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_int(va_list arg, t_infos *infos)
{
	long long int	integer;
	char			*ret;

	integer = va_arg(arg, long long int);
	//printf("prec: %d\n", infos->prec);
	if (integer == 0)
		ret = "0";
	if (is_modif(infos->modif[0]) == 0 && (infos->conv == 'd'
				|| infos->conv == 'i'))
	{
		integer = (int)integer;
		ret = ft_itoa(integer);
	}
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h' && (infos->conv == 'd'
					|| infos->conv == 'i'))
			integer = (signed char)integer;
		else
		{
			if (infos->conv == 'D')
				integer = (unsigned short)integer;
			else
				integer = (short)integer;
		}
		ret = ft_itoa(integer);
	}
	if (infos->modif[0] == 'l' && infos->modif[1] != 'l')
	{
		integer = (long int)integer;
		ret = ft_itoa_long(integer);
	}
	if (infos->conv == 'D' || infos->modif[1] == 'l'
			|| infos->modif[0] == 'j' || infos->modif[0] == 'z')
		ret = ft_itoa_long(integer);
	ret = addFlagInteger(infos->flag, ret);
	if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret))
		ret = addPrec(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);
	if (integer == 0 && (infos->prec == -2 || infos->prec == -3))
		ret = "";
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_unsigned(va_list arg, t_infos *infos)
{
	unsigned long int	u;
	char				*ret;

	u = va_arg(arg, unsigned long int);
	if (infos->modif[0] == 'h' && infos->conv == 'u')
	{
		if (infos->modif[1] == 'h' && infos->conv == 'u')
			u = (unsigned char)u;
		else
			u = (unsigned short)u;
	}
	if (infos->conv == 'u' && is_modif(infos->modif[0]) == 0)
		ret = ft_uitoa((unsigned int)u);
	else
		ret = ft_uitoa_long((unsigned long int)u);
	if (u == 0)
		ret = "0";
	if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret))
		ret = addPrec(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);
	if (u == 0 && (infos->prec == -2 || infos->prec == -3))
		ret = "";
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_string(va_list arg, t_infos *infos)
{
	char	*string;
	int 	i;

	i = 0;
	string = va_arg(arg, char *);
	if (string == 0)
		string = "(null)";
	else if (string == '\0' && infos->width != 0)
	{
		while (i++ < infos->width)
 			ft_putchar('0');
		return (i - 1);
	}
	if (infos->prec == -2 || infos->prec == -3)
		string = "";
	if (infos->prec > 0)
		string = addPrecString(string, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(string))
		string = addWidth(string, infos->width, infos->flag);
	ft_putstr(string);
	//printf("str ret: %d\n", (int)ft_strlen(string));
	return (ft_strlen(string));
}

int		convert_pointer(va_list arg, t_infos *infos)
{
	unsigned long int	addr;
	char				*ret;

	addr = va_arg(arg, unsigned long int);
	ret = baseHexa(addr, 0);
	if (addr == 0 && (infos->prec == -2 || infos->prec == -3))
		ret = "";
	ret = add0xAddr(ret);
	//printf("prec: %d\n", infos->prec);
	if (infos->prec > 0)
		ret = addPrecHexa(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = addWidth0x(ret, infos->width, infos->flag);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_char(va_list arg, t_infos *infos)
{
	unsigned int	c;
	int				i;
	char			*ret;

	c = va_arg(arg, unsigned int);
	c = (char)c;
	i = 0;
	if (c <= 126)
	{
		if (infos->width > 0)
		{
			ret = (char *)malloc(sizeof(char) * infos->width);
			while (i < infos->width - 1)
			{
				if (infos->flag[0] == '0')
					ret[i] = '0';
				else
					ret[i] = ' ';
				i++;
			}
			ret[i++] = c;
			ret[i] = '\0';
			ft_putstr(ret);
			return (i);
		}
		ft_putchar(c);
		return (1);
	}
	return (0);
}
