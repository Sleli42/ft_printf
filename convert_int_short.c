/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_short.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 02:43:19 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/07 06:50:39 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*convert_int_short(int integer)
{
	int		tmp;
	int		ret;
	char 	*izi;

	if (integer <= 32767 && integer >= -32768)
		return (ft_itoa(integer));
	else if (integer == -32769)
	{
		ret = 32767;
	//	printf("malloc for life: %d\n", ret);
		return (ft_itoa(ret));
	}	
	else if (integer == 32768)
	{
		ret = -32768;
		//printf("malloc pr toujours: %d\n", ret);
		return (ft_itoa(ret));
	}
	else if (integer < -32767)
	{
		izi = convert_negative_int(integer);
		return (izi);
	}
	else if (integer > 32767)
	{
		izi = convert_positive_int(integer);
	}
	return (NULL);
}

char	*convert_negative_int(int integer)
{
	int tmp;
	int ret;

	if (integer < -32767)
	{
		tmp = (-32768) - integer;
	//	printf("lucas est fatigue: %d\n", tmp);
		ret = 32768 - tmp;
	//	printf("lucas est naze lol:%d\n", ret);
	}
	return (ft_itoa(ret));
}


char	*convert_positive_int(int integer)
{
	int	tmp;
	int	ret;

	if (integer > 32767)
	{
		tmp = 32768 - integer;
	//	printf("sami est une salope:%d\n", tmp);
		ret = -32768 - tmp;
	//	printf("sami est vraiment une grosse salope:%d\n", ret);
	}
	return (ft_itoa(ret));
}
