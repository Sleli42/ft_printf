/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 12:55:21 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/23 02:21:41 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/02/19 23:12:48 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strrev(char const *s)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	//printf("[strrev] s: %s\n", s);
	i = ft_strlen(s) - 1;
	j = 0;
	while (i >= 0)
		ret[j++] = s[i--];
	ret[j] = '\0';
	//printf("[strrev] ret: %s\n", ret);
	return (ret);
}
