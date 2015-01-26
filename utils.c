/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:49:01 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/26 06:11:46 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_ulong(unsigned long long int n)
{
	char	*ret;
	unsigned long long int		temp_n;
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

char	*ft_itoa_long(long long int n)
{
	char	*ret;
	long long int		temp_n;
	size_t	size_ret;
	char	sign;

	//printf("n recu : %lld", n);
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

char	*ft_uitoa(unsigned int n)
{
	char	*ret;
	unsigned int		temp_n;
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
