/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 21:42:21 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 01:51:21 by lubaujar         ###   ########.fr       */
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

int		wstrlen(wchar_t *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		convert_wchar_string(va_list arg, t_infos *infos)
{
	wchar_t		*ws;
	int			i;
	int			ret;
	int			tmp;
	int			tmp2;

	i = 0;
	ret = 0;
	tmp = 0;
	tmp2 = 0;
	ws = va_arg(arg, wchar_t *);
	if (ws == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (infos->prec == -2)
		ws = L"";
	if (infos->prec > 0 || infos->prec == -2)
	{
		tmp = definePrecWchar(infos->prec - 1);
		if (infos->width >= 0 && tmp >= 0)
		{
			while (infos->width > tmp++)
			{
				if (infos->flag[0] == '0')
					ft_putchar('0'), tmp2++;
				else
					ft_putchar(' '), tmp2++;
			}
		}
	}
	else
	{
		if (infos->width > 0 && infos->flag[0] != '-')
		{
			while (infos->width-- > (wstrlen(ws) * 3))
			{
				if (infos->flag[0] == '0')
					ft_putchar('0'), tmp2++;
				else
					ft_putchar(' '), tmp2++;
			}
		}
	}
	if (ws[i + 1] == '\0' && infos->prec != -2)
		return (printWchar(ws[i]));
	else
	{
		if (infos->prec > 0)
		{
			if (infos->prec > 1)
				while (ret < infos->prec - 1)
					ret += printWchar(ws[i++]);
			else if (infos->prec == 1)
			{
				while (ret < infos->prec)
					ret += printWchar(ws[i++]);
			}
		}
		else
			while (ws[i])
				ret += printWchar(ws[i++]);
	}
	if (infos->flag[0] == '-' && infos->width > (wstrlen(ws) * 3))
	{
		while (infos->width - (wstrlen(ws) * 3) > 0)
		{
			if (infos->flag[1] == '0')
				ft_putchar('0'), tmp2++;
			else
				ft_putchar(' '), tmp2++;
			infos->width--;
		}
	}
	if (tmp2 > 0)
		ret += tmp2;
	return (ret);
}

int		definePrecWchar(int prec)
{
	//	printf("prec recu: |%d|\n", prec);
	if (prec < 0)
		return (0);
	else if (prec == 0)
		return (1);
	else if (prec > 1 && prec <= 3)
		return (3);
	else if (prec <= 6)
		return (6);
	else if (prec <= 9)
		return (9);
	else if (prec <= 12)
		return (12);
	else if (prec <= 15)
		return (15);
	else if (prec <= 18)
		return (18);
	return (0);
}
