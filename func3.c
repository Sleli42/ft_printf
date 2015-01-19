/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 09:54:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/19 17:41:24 by lubaujar         ###   ########.fr       */
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
	//printf("flag: %s\n", flag);
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

char	*add_0x_addr(char *s, int spec)
{
	char	*ret;
	char	*tmp;
	int		i;

	ret = (char *)malloc(sizeof(ft_strlen(s)) + 2);
	i = 2;
	ret[0] = '0';
	if (spec == 0)
		ret[1] = 'x';
	else if (spec == 1)
		ret[1] = 'X';
	while (*s)
		ret[i++] = *s++;
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
			ret = add_0x_addr(ret, spec);
	}
	return (ret);
}


