/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 03:45:37 by lubaujar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/26 06:11:36 by lubaujar         ###   ########.fr       */
=======
/*   Updated: 2015/01/22 06:46:59 by lubaujar         ###   ########.fr       */
>>>>>>> 6a28af0bcf888285c38135839391b5e3289c1eac
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_precision(char *integer, unsigned int precision)
{
	char	*ret;
	int		i;

	ret = ft_strnew(precision);
	i = 0;
	if (integer[0] == '-')
	{
		ret[i++] = '-';
		while (i <= precision - ft_strlen(integer) + 1)
			ret[i++] = '0';
		*integer++;
		while (*integer)
			ret[i++] = *integer++;
	}
	else if (integer[0] != '-')
	{
		if (integer[0] == '+')
		{
			ret[i++] = '+';
			integer[0] = '0';
			while ((i - 1) < precision - ft_strlen(integer))
				ret[i++] = '0';
			while (*integer)
				ret[i++] = *integer++;
			return (ret);
		}		
		while (i < precision - ft_strlen(integer))
			ret[i++] = '0';
		while (*integer)
			ret[i++] = *integer++;
	}
	return (ret);
}

char	*add_width(char *integer, unsigned int width, char *flag, unsigned int precision)
{
	char	*ret;
	int		i;

	if (flag[0] == '0' && precision < width && precision != 0)
		flag[0] = 'p';
	if (*flag == '-')
	{
		ret = add_width_less(integer, width);
		return (ret);
	}
	if (width <= ft_strlen(integer))
		return (integer);
	ret = ft_strnew(width);
	i = 0;
	while (i < width - ft_strlen(integer))
	{
		if (flag[0] == '0')
		{
			ret[0] = '-';
			ret[++i] = '0';
			integer[0] = '0';
		}
		else
			ret[i++] = ' ';
	}
	while (*integer)
		ret[i++] = *integer++;
	return (ret);
}
char	*add_width_less(char *integer, unsigned int	width)
{
	char	*ret;
	int		i;

	if (width <= ft_strlen(integer))
		return (integer);
	ret = ft_strnew(width);
	i = 0;
		while (*integer)
			ret[i++] = *integer++;
		while (i < width)
			ret[i++] = ' ';
	return (ret);
}
char	*add_flag(char *integer, char flag)
{
	char	*ret;

	if (flag == '+')
		ret = add_flag_plus(integer);
	else
		ret = integer;
	return (ret);		
}
char	*add_flag_space(char *integer)
{
	int 	i;
	char 	*ret;

	ret = ft_strnew(ft_strlen(integer) + 1 );
	ret[0] = ' ';
	i = 1;
	while (*integer)	
	{
		ret[i++] = *integer++;
	}
	return (ret);
}

char	*add_flag_plus(char *integer)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	ret = ft_strnew(ft_strlen(integer) + 1);
	if (integer[i] == '-')
		return (integer);
	if (integer[i] != '-')
		tmp = cpy_integer_with_sign(integer);
	return (tmp);
}

char	*cpy_integer_with_sign(char *integer)
{
	char	*ret;
	int		i;
	int		j;
	int		len;

	j = 0;
	len = 0;
	while (integer[j++])
	{
		if (integer[j] >= '0' && integer[j] <= '9')
			len++;
	}
	ret = (char *)malloc(sizeof(len) + 1);
	j = 0;
	while (integer[j] == ' ')
		integer[j++];
	i = 0;
	ret[i++] = '+';
	while (integer[j])
		ret[i++] = integer[j++];
	return (ret);
}
