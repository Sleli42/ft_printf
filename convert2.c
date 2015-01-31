/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 21:42:21 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/31 03:59:28 by lubaujar         ###   ########.fr       */
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
	ret = baseOctal(o);
	if (infos->prec > 0 && infos->prec > ft_strlen(ret))
		ret = addPrec(ret, infos->prec);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_hexa(va_list arg, t_infos *infos)
{
	unsigned long long int	x;
	char				*ret;

	x = va_arg(arg, unsigned long long int);
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h')
			x = (unsigned char)x;
		else
			x = (unsigned short)x;
	}
	if (infos->conv == 'x')
		ret = baseHexa(x, 0);
	else
		ret = baseHexa(x, 1);
	if (infos->width > 0 && infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);
	ft_putstr(ret);
	return (ft_strlen(ret));
}
