/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:50:43 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/31 04:10:43 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_infos
{
	char	flag;
	int		width;
	int		precision;
	char	modifier;
	char	type;
}				t_infos;

//	if_infos
int		is_flag(char c);

//	search
int		search_flag(char *s, int caract, t_infos *lst);

#endif
