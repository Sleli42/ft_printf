/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 21:42:21 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/24 07:18:42 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_long_int(va_list arg, t_infos *infos)
{
	long int	i;
	char		*ret;

	i = va_arg(arg, long int);
	//ret = (char *)malloc(sizeof(char) + 1);
	if (i == 0)
		ret = "0";
	if (infos->modif[0] == 'h')
		i = (unsigned short)i;
	ret = ft_itoa_long(i);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

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
	if (o == 0)
		ret = "0";
	if (infos->flag[0] == '#' && o != 0)
		ret = addSharpOctal(ret);
	if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret))
		ret = addPrec(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);
	if (o == 0 && (infos->prec == -2 || infos->prec == -3)
		   	&& infos->flag[0] != '#')
		ret = "";
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_hexa(va_list arg, t_infos *infos)
{
	unsigned long long int	x;
	char				*ret;

	x = va_arg(arg, unsigned long long int);

	if (x == 0)
		ret = "0";
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
	if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret) && infos->flag[0] != '#')
	{
		ret = addPrecAddr(ret, infos->prec);
	//	printf("ret = %s\n", ret);
	}
	else if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret))
	{
		ret = addPrecHexa(ret, infos->prec);
		//printf("ret = %s\n", ret);
	}
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = addWidth(ret, infos->width, infos->flag);	
	if (x == 0 && (infos->prec == -2 || infos->prec == -3))
		ret = "";
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_wchar(va_list arg, t_infos *infos)
{
	wchar_t		wc;
	int			tmp;
//	int			ret;
//	char		*bin;

	wc = va_arg(arg, wchar_t);
	tmp = (int)wc;
	infos = infos;
	/*ret = 0;
	//printf("bin: %s\n", bin);
	bin = baseBinary(tmp);
	infos = infos;
	if ((int)ft_strlen(bin) <= 7)
	{
		write(1, &tmp, 1);
		ret = 1;
	}
	else
		ret = maskUnicode(bin, ft_strlen(bin));*/
	return (printWchar(tmp));
}

int		convert_wchar_string(va_list arg, t_infos *infos)
{
	wchar_t		*ws;
	int			i;
	int			ret;
	int			tmp;

	i = 0;
	ret = 0;
	tmp = 0;
	ws = va_arg(arg, wchar_t *);
	if (ws == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	//printf("value: %C\n", ws[i + 1]);
	while (ws[tmp])
		tmp++;
	if (infos->width > 0 && infos->flag[0] != '-')
		ret = addWidthWchar((infos->width - (tmp * 3)), infos->flag);
	if (ws[i + 1] == '\0')
		return (printWchar(ws[i]));
	else
		while (ws[i])
			ret += printWchar(ws[i++]);
	if (infos->width > 0 && infos->flag[0] == '-')
		ret += addWidthWchar((infos->width - ret), infos->flag);
	return (ret);
}
