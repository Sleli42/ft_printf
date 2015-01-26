/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 09:54:14 by lubaujar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/26 06:11:43 by lubaujar         ###   ########.fr       */
=======
/*   Updated: 2015/01/22 09:32:26 by lubaujar         ###   ########.fr       */
>>>>>>> 6a28af0bcf888285c38135839391b5e3289c1eac
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_precision_string(char *s, int precision)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * precision);
	i = 0;
	if (precision > ft_strlen(s))
		return (s);
	if (precision < ft_strlen(s))
	{
		while (*s)
		{
			if (i < precision)
				ret[i++] = *s;
			*s++;
		}
		return (ret);
	}
	return (NULL);
}

char	*add_width_string(char *s, int width, char *flag)
{
	char	*ret;
	int		i;

	ret = ft_strnew(width);
	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
<<<<<<< HEAD
		return (s);
=======
		return ;
>>>>>>> 6a28af0bcf888285c38135839391b5e3289c1eac
	}
	if (width < ft_strlen(s) || width == ft_strlen(s))
		return (s);
	if (flag[0] == '-')
	{
		while (*s)
			ret[i++] = *s++;
		while (i < width)
			ret[i++] = ' ';
		return (ret);
	}
	if (width > ft_strlen(s))
	{
		while (i < width - ft_strlen(s))
		{
			if (flag[0] != '0')
				ret[i++] = ' ';
			else 
				ret[i++] = '0';
		}
		while (*s)
			ret[i++] = *s++;
		return (ret);
	}
	return (NULL);
}

static int		hexa_value(int n)
{
	if (0 <= n && n <= 9)
		return (48 + n);
	else if (10 <= n && n <= 15)
	{
		n = n - 10;
		return (97 + n);
	}
	return (0);
}
static int		hexa_value_maj(int n)
{
	if (0 <= n && n <= 9)
		return (48 + n);
	else if (10 <= n && n <= 15)
	{
		n = n - 10;
		return (65 + n);
	}
	return (0);
}

char	*add_0x_addr(char *s, int spec, int precision, int width)
{
	char	*ret;
	char	*tmp;
	int		i;

	ret = (char *)malloc(sizeof(ft_strlen(s)) + 3);
	i = 2;
	ret[0] = '0';
	if (spec == 0)
		ret[1] = 'x';
	else if (spec == 1)
		ret[1] = 'X';
	if (ft_strlen(s) < 12 && ft_strlen(s) >= 8)
	{
		if (s[0] != '7')
			ret[i++] = '1';
	}
	while (*s)
		ret[i++] = *s++;
	if (precision > 0)
		ret = add_precision_addr(ret, precision);
	if (width > 0)
		ret = add_width_addr(ret, width);
	return (ret);
}

char			*hexa_convert(unsigned long int n, int spec, char flag)
{
	char			*ret;
	int				i;
	unsigned long int		tmp;

	tmp = n;
	i = 0;
	while (tmp > 16)
	{
		tmp = tmp / 16;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret)
	{
		ret[i + 1] = '\0';
		while (i >= 0)
		{
			tmp = n % 16;
			if (spec == 0)
				ret[i] = hexa_value(tmp);
			if (spec == 1)
				ret[i] = hexa_value_maj(tmp);
			n = n / 16;
			i--;
		}
		if (flag == '#')
			ret = add_0x_addr(ret, spec, 0, 0);
	}
	return (ret);
}


