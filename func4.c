/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:26:45 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/21 21:46:58 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_0(char *s)
{
	char	*ret;
	int		i;

	ret = ft_strnew(ft_strlen(s) + 1);
	i = 1;
	ret[0] = '0';
	while (*s)
		ret[i++] = *s++;
	return (ret);

}

char			*octal_convert(unsigned long int n, char flag)
{
	char			*ret;
	int				i;
	unsigned long int		tmp;

	tmp = n;
	i = 0;
	while (tmp > 7)
	{
		tmp = tmp / 8;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret)
	{
		ret[i + 1] = '\0';
		while (i >= 0)
		{
			tmp = n % 8;
			ret[i] = 48 + tmp;
			n = n / 8;
			i--;
		}
		if (flag == '#')
			ret = add_0(ret);
	}
	return (ret);
}

char	*add_o_precision(char *s, int precision)
{
	char	*ret;
	int		i;

	ret = ft_strnew(precision);
	i = 0;
	while (i < precision - ft_strlen(s))
		ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	return (ret);
}

char	*add_o_width(char *s, int width, char flag, int precision)
{
	char	*ret;
	int		i;

	ret = ft_strnew(width);
	i = 0;
	if (flag == '-')
	{
		ret = offset_left(s, width);
		return (ret);
	}
	while (i < width - ft_strlen(s))
	{
		if (flag == '0' && precision == 0)
			ret[i++] = '0';
		else
			ret[i++] = ' ';
	}
	while (*s)
		ret[i++] = *s++;
	return (ret);
}

char	*add_0x1_addr(char *s)
{
	char *ret;
	int	i;

	ret = ft_strnew(ft_strlen(s) + 4);
	i = 0;
	if (s)
	{
		ret[i++] = '0';
		ret[i++] = 'x';
		//ret[2] = '1';
		while (*s)
			ret[i++] = *s++;
		return (ret);
	}
	else
		return (NULL);
}
