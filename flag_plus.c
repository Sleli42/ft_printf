/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:38:12 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/07 06:50:04 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*cpy_int_without_sign(char *c_int)
{
	char	*ret;
	int		i;
	int		j;

	ret = ft_strnew(ft_strlen(c_int));
	i = 0;
	j = 0;
	while (j < ft_strlen(c_int))
		ret[j++] = c_int[i++];
	ret[j] = '\0';
	return (ret);
}

char	*recover_int(char *c_int)
{
	char	*ret;
	int		i;

	i = 1;
	ret = ft_strnew(ft_strlen(c_int) + 1);
	ret[0] = '+';
	while (*c_int)
		ret[i++] = *c_int++;
	ret[i] = '\0';
	return (ret);
}

char	*add_precision_int(int precision, char *c_int, int integer)
{
	char	*ret;
	int		i;

	printf("c_int:%s\n", c_int);
	i = 0;
	ret = ft_strnew(precision + 1);
	if (integer >= 0 || c_int[0] != '-')
	{
		i = 1;
		ret[0] = '+';
	}
	else
	{
		ret[0] = '-';
		c_int = cpy_int_without_sign(c_int);
	}
	if (c_int[0] == '+' || c_int[0] == '-')
		c_int[0] = '0';
	while (i <= precision - ft_strlen(c_int))
		ret[i++] = '0';
	while (i < precision + 1 && *c_int)
		ret[i++] = *c_int++;
	ret[i] = '\0';
	return (ret);
}

char	*add_width_int(int width, char *temp)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(width + 1);
	while (i < width - ft_strlen(temp))
		ret[i++] = ' ';
	while (i < width)
		ret[i++] = *temp++;
	ret[i] = '\0';
	return (ret);
}
