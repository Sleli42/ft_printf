/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:50:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/06 06:41:20 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/*
typedef struct	s_list
{
	struct s_infos	*troncon;
	struct s_list	*next;
				t_list;
}
*/
typedef struct	s_infos
{
	char	*flag;
	int		width;
	int		precision;
	char	*modifier;
	char	type;
}				t_infos;

//	if_infos
int		is_flag(char c);

//	search
int		search_flag(char *s, int caract, t_infos *lst);
void	display_struct(t_infos lst);


#endif
