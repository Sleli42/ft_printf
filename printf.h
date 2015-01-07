/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:50:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/07 06:50:30 by lubaujar         ###   ########.fr       */
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

char	*recover_int(char *c_int);
char	*add_precision_int(int precision, char *c_int, int integer);
char	*add_width_int(int width, char *temp);
char	*cpy_int_without_sign(char *c_int);
char	*find_modifier(char *modifier, int integer);
char	*convert_int_short(int integer);
char	*convert_negative_int(int integer);
char	*convert_positive_int(int integer);
char	*ft_strnew(size_t size);


#endif
