/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 12:55:21 by lubaujar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/23 14:55:27 by lubaujar         ###   ########.fr       */
=======
/*   Updated: 2015/01/22 13:14:59 by lubaujar         ###   ########.fr       */
>>>>>>> 6a28af0bcf888285c38135839391b5e3289c1eac
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_strrev(char *str)
{
	int			i;
	int			length;
	char		tmp;

	if (str)
	{
		i = 0;
<<<<<<< HEAD
		length = (ft_strlen(str));
=======
		length = ft_strlen(str);
>>>>>>> 6a28af0bcf888285c38135839391b5e3289c1eac
		while (i < length / 2)
		{
			tmp = str[i];
			str[i] = str[length - i - 1];
			str[length - i - 1] = tmp;
			i++;
		}
	}
	return (str);
}
<<<<<<< HEAD

=======
>>>>>>> 6a28af0bcf888285c38135839391b5e3289c1eac
