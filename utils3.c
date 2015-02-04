/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:55:02 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/04 08:27:26 by lubaujar         ###   ########.fr       */
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
