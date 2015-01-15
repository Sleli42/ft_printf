/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 03:45:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/15 08:09:09 by lubaujar         ###   ########.fr       */
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
		while (i < precision - ft_strlen(integer))
			ret[i++] = '0';
		while (*integer)
			ret[i++] = *integer++;
	}
	return (ret);
}

char	*add_width(char *integer, unsigned int width)
{
	char	*ret;
	int		i;

	//	printf("tailel inte: %d\n", ft_strlen(integer));
	if (width <= ft_strlen(integer))
		return (integer);
	ret = ft_strnew(width);
	i = 0;
	if (integer[0] == '-')
	{
		//	printf("len: %d\n\n", ft_strlen(integer));
		//	printf("width: %d\n\n", width);
		while (i < width - ft_strlen(integer))
			ret[i++] = ' ';
		while (*integer)
			ret[i++] = *integer++;
	}
	if (integer[0] != '-')
	{
		while (i < width - ft_strlen(integer))
			ret[i++] = ' ';
		while (*integer)
			ret[i++] = *integer++;
	}
	return (ret);
}

char	*add_flag(char *integer, char flag)
{
	char	*ret;

	if (flag == '+')
		ret = add_flag_plus(integer);
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
