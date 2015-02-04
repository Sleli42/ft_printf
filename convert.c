/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 20:42:39 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/04 09:57:35 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_int(va_list arg, t_infos *infos)
{
	long long int	integer;
	char			*ret;

	integer = va_arg(arg, long long int);
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
	if (infos->flag[0] == ' ' && infos->flag[1] == '+')
		ret = addPlus(ret);
	else if (infos->flag[0] == '+' && infos->flag[1] == '0' && integer == 0)
	{
		ret = addSharpOctal(ret);
		ret = addPlus(ret);
	}
	else if (infos->flag[0] == '+' && infos->flag[1] == '0' && integer > 0)
		ret = addPlus(ret);
	else if (infos->flag[0] == ' ' && infos->flag[1] == '0')
	{
		ret = addSharpOctal(ret);
		ret = addSpace(ret);
	}
	else if (infos->flag[0] == '+' && ret[0] != '-')
		ret = addPlus(ret);
	else if (infos->flag[0] == ' ' && ret[0] != '-')
		ret = addSpace(ret);
	//printf("ret->|%s|", ret);
	if (infos->prec > 0 && infos->prec > ft_strlen(ret))
		ret = addPrec(ret, infos->prec);
	if (infos->width > 0 && infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);
	// error
	if (infos->prec == -1 && integer == 0)
		return (0);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_unsigned(va_list arg, t_infos *infos)
{
	unsigned long int	u;
	char				*ret;

	u = va_arg(arg, unsigned long int);
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h' && infos->conv == 'u')
			u = (unsigned char)u;
		else
			u = (unsigned short)u;
	}
	if (infos->conv == 'u' && is_modif(infos->modif[0]) == 0)
		ret = ft_uitoa((unsigned int)u);
	else
	{
		//printf("unsigned: %U", u);
		ret = ft_uitoa_long((unsigned long int)u);
	}
	if (infos->prec > 0 && infos->prec > ft_strlen(ret))
		ret = addPrec(ret, infos->prec);
	if (infos->width > 0 && infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);
	if (infos->prec == -1 && u == 0)
		return (0);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_string(va_list arg, t_infos *infos)
{
	char	*string;

	string = va_arg(arg, char *);
	if (string == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (infos->prec > 0 || infos->prec == -1)
		string = addPrecString(string, infos->prec);
	if (infos->width > 0 && infos->width > ft_strlen(string))
		string = addWidth(string, infos->width, infos->flag);
	ft_putstr(string);
	return (ft_strlen(string));
}

int		convert_pointer(va_list arg, t_infos *infos)
{
	unsigned long int	addr;
	char				*ret;

	addr = va_arg(arg, unsigned long int);
	ret = baseHexa(addr, 0);
	ret = add0xAddr(ret);
	if (infos->prec > 0 || infos->prec == - 1)
		ret = addPrecAddr(ret, infos->prec);
	if (infos->width > 0 && infos->width > ft_strlen(ret))
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
	if (c >= 0 && c <= 126)
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
