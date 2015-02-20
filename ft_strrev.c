/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 12:55:21 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/19 23:12:48 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strrev(char	*s)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = ft_strlen(s);
	j = 0;
	while (i > 0)
		ret[j++] = s[i--];
	ret[j] = '\0';
	return (ret);
}
