/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/07 06:50:27 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	convert_int(va_list arg, t_infos *lst)
{
	int		integer;
	int		i;
	t_infos	*tmp;

	integer = va_arg(arg, int);
	tmp = lst;
	if (tmp->flag != NULL)
		find_flag_int(tmp->flag, integer, tmp);
}
