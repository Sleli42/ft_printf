/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 00:21:34 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/22 06:12:06 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_precision_addr(char *ret, int precision)
{
	int 	i;
	int 	j;
	char *cpy;

	i = ft_strlen(ret) + precision; 
	cpy = ft_strnew(i);
	i = 2;
	j = 2;
	cpy[0] = ret[0];
	cpy[1] = ret[1];
	while (i < ((precision - ft_strlen(ret)) + 4))
		cpy[i++] = '0';
	while (ret[j])   
		cpy[i++] = ret[j++];
	cpy[i] = '\0';
	return (cpy);
}

char	*add_width_addr(char *ret, int width)
{
	int i;
	int c;
	char *cpy;

	c = width - ft_strlen(ret);
	cpy = ft_strnew(width + ft_strlen(ret));
	i = 0;
	while (i < c && c > 0)
		cpy[i++] = ' ';
	while(*ret)
		cpy[i++] = *ret++;
	cpy[i] == '\0';
	return (cpy);
}
