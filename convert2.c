/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 21:42:21 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/04 09:28:24 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_octal(va_list arg, t_infos *infos)
{
	unsigned long long int	o;
	char				*ret;

	o = va_arg(arg, unsigned long long int);
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h' && infos->conv == 'o')
			o = (unsigned char)o;
		else
			o = (unsigned short)o;
	}
	if (infos->conv == 'o' && is_modif(infos->modif[0]) == 0)
		o = (unsigned int)o;
	if (infos->prec == -1 && o == 0 && infos->flag[0] == '\0')
		return (0);
	ret = baseOctal(o);
	if (infos->flag[0] == '#' && o != 0)
		ret = addSharpOctal(ret);
	if (infos->prec > 0 && infos->prec > ft_strlen(ret))
		ret = addPrec(ret, infos->prec);
	if (infos->width > 0 && infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_hexa(va_list arg, t_infos *infos)
{
	unsigned long long int	x;
	char				*ret;

	x = va_arg(arg, unsigned long long int);

	if (x == 0 && infos->flag[0] == '#' && infos->prec == -1)
		return (0);
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h')
			x = (unsigned char)x;
		else
			x = (unsigned short)x;
	}
	if (infos->conv == 'x')
	{
		ret = baseHexa(x, 0);
		if (infos->flag[0] == '#' && x != 0)
			ret = addSharpHexa(ret, 0);
	}
	else
	{
		ret = baseHexa(x, 1);
		if (infos->flag[0] == '#' && x != 0)
			ret = addSharpHexa(ret, 1);
	}
	if (infos->prec == -1 && x == 0 && infos->flag[0] == '\0')
		return (0);
	if (infos->prec > 0 && infos->prec > ft_strlen(ret) && infos->flag[0] != '#')
	{
		ret = addPrecAddr(ret, infos->prec);
		//printf("ret = %s\n", ret);
	}
	else if (infos->prec > 0 && infos->prec > ft_strlen(ret))
	{
		ret = addPrecHexa(ret, infos->prec);
		//printf("ret = %s\n", ret);
	}
	if (infos->width > 0 && infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);	
	ft_putstr(ret);
	return (ft_strlen(ret));
}
