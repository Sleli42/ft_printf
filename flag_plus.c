/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 22:38:12 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/14 09:30:37 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*cpy_int_without_sign(char *c_int)
{
	char	*ret;
	int		i;
	int		j;

	ret = ft_strnew(ft_strlen(c_int));
	i = 1;
	j = 0;
	if (ft_atoi_long(c_int) < 0)
		i = 1;
	while (j < ft_strlen(c_int))
		ret[j++] = c_int[i++];
	ret[j] = '\0';
	return (ret);
}

char	*recover_int(char *c_int, char *modifier, int precision)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(ft_strlen(c_int) + 1);
	if ((is_modifier(modifier[0]) != 1 && precision == 0)
			|| (is_modifier(modifier[0]) == 1 && precision == 0 && c_int[0] != '-'))
	{
		ret[0] = '+';
		i = 1;
	}
	while (*c_int)
		ret[i++] = *c_int++;
	ret[i] = '\0';
	return (ret);
}

char	*add_precision_int(int precision, char *c_int, long long int integer, char *modifier)
{
	char	*ret;
	int		i;
	int 	j;

	printf("test1 %s\n", ret);
	i = 0;
	j = precision - ft_strlen(c_int) + 1;
	if (ft_strlen(c_int) > precision)
		ret = ft_strnew(ft_strlen(c_int) + 1);
	else
		ret = ft_strnew(precision + 1);	
	if (integer > 32767 && is_modifier(modifier[0]) == 'h')
	{
		ret[0] = '-';
		printf("yolo");
	}
	else if ((integer >= 0 && integer <= 32767)
		   || (integer >= 0 && c_int[0] != '-'))
	{
		ret[0] = '+';
	}
	else if ((c_int[0] == '-' && integer >= 0 && integer <= 32767)
			|| (c_int[0] == '-' && integer < 0 && precision > ft_strlen(c_int)))
	{
		ret[0] = '-';
		c_int = cpy_int_without_sign(c_int);
		j = j + 1;
	}
	else if ((c_int[0] == '+' || c_int[0] == '-')
		   	&& (*modifier != 'l' && modifier != "ll" && *modifier != 'h'))
	{
		c_int[0] = '0';
	}
	while (i < j && j > 0)
	{
		ret[++i] = '0';
		printf("ret incrementation :%c\n", ret[i]);
	}	
	while (*c_int)
		ret[i++] = *c_int++;
	ret[i] = '\0';
	printf("result precision %s\n", ret);
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
