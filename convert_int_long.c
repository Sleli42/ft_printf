/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 01:33:45 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/16 13:09:54 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	convert_int_long(long long int integer)
{
	ft_putnbr_long(integer);
}

void	ft_putnbr_long(long long int integer)
{
	if (integer < 0)
	{
		ft_putchar('-');
		integer = -integer;
	}
	if (integer > 9)
	{
		ft_putnbr_long(integer / 10);
		ft_putnbr_long(integer % 10);
	}
	else
		ft_putchar(integer + 48);
}

char	*ft_itoa_long(long long int n)
{
	char	*ret;
	long long int		temp_n;
	size_t	size_ret;
	char	sign;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		size_ret++;
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * size_ret--)) == NULL)
		return (NULL);
	ret[size_ret--] = '\0';
	ret[size_ret--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		ret[size_ret--] = sign * (n % 10) + '0';
	if (sign < 0)
		ret[size_ret] = '-';
	return (ret);
}

long long int	ft_atoi_long(char *s)
{
	unsigned int				digit;
	long long int				positive;
	long long int				value;

	value = 0;
	digit = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n'
			|| *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	positive = (*s == '-' ? -1 : 1);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '0')
		s++;
	if (ft_strlen(s) > 19)
		return (positive == 1 ? -1 : 0);
	while (ft_isdigit(*s) && *s)
	{
		digit = (long long int)(*s - '0');
		value = (value * 10) + digit;
		s++;
	}
	return (value * positive);
}
