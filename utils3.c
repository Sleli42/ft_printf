/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:55:02 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/06 18:27:02 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*addSharpHexa(char *s, int spec)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 3);
	i = 0;
	ret[i++] = '0';
	if (spec == 1)
		ret[i++] = 'X';
	else
		ret[i++] = 'x';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*addPlus(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = '+';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*addSpace(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = ' ';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*addPrecAddr(char *s, int prec)
{
	char	*ret;
	int		i;
	int		len;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + prec) + 1);
	i = 0;
	len = ft_strlen(s);
	if (prec == -1)
	{
		ret[0] = '0';
		ret[1] = 'x';
		ret[2] = '\0';
		return (ret);
	}	
	while (i < prec - len)
		ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*addPrecHexa(char *s, int prec)
{
	char	*ret;
	int		i;
	int		len;
	int 	j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + prec) + 1);
	i = 2;
	j = 2;
	if (prec == -1)
	{
		ret[0] = '0';
		ret[1] = 'x';
		ret[2] = '\0';
		return (ret);
	}
	len = ft_strlen(s);
	ret[0] = '0';
	ret[1] = 'x';
	while (i < (prec - len) + 4)
		ret[i++] = '0';
	while (s[j])
		ret[i++] = s[j++];
	ret[i] = '\0';
	return (ret);
}
