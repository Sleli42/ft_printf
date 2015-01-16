/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 02:05:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/16 05:04:13 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	affiche_detect(t_infos *lst)
{
	t_infos	*tmp;

	tmp = lst;
	printf("flags: %s\n", tmp->flag);
	printf("modifier: %s\n", tmp->modifier);
	printf("width: %d\n", tmp->width);
	printf("precision: %d\n", tmp->precision);
	printf("type: %c\n", tmp->type);
}
