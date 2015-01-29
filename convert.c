/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 20:42:39 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/29 03:37:20 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include "../../libft/libft.h"

int		convert_int(va_list arg, t_infos *infos)
{
	long long int	integer;
	char			*ret;

	integer = va_arg(arg, long long int);
	//printf("irecu: %d", integer);
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h')
			integer = (signed char)integer;
		else
			integer = (short)integer;
	}
	else if (infos->modif[0] == 'l' && infos->modif[1] != 'l')
		integer = (long int)integer;
	else if (is_modif(infos->modif[0]) == 0)
	{
		integer = (int)integer;
		ret = ft_itoa(integer);
	}
	else
		ret = ft_itoa_long(integer);
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
		if (infos->modif[1] == 'h')
			u = (unsigned char)u;
		else
			u = (unsigned short)u;
	}
	if (infos->conv == 'u')
		ret = ft_uitoa((unsigned int)u);
	else
		ret = ft_itoa_long((unsigned long int)u);
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
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_char(va_list arg, t_infos *infos)
{
	unsigned int	c;

	c = va_arg(arg, unsigned int);
	c = (char)c;
	if (c >= 0 && c <= 126)
	{
		ft_putchar(c);
		return (1);
	}
	return (0);
}
