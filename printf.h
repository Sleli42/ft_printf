/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:50:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/17 19:42:29 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "../../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>
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

char	*recover_int(char *c_int, char *modifier, int precision);
char	*add_precision_int(int precision, char *c_int, long long int integer, char *modifier);
char	*add_width_int(int width, char *temp);
char	*cpy_int_without_sign(char *c_int);
char	*find_modifier(char *modifier, long long int integer);
char	*convert_int_short(int integer);
char	*convert_negative_int(int integer);
char	*convert_positive_int(int integer);
void	ft_putnbr_long(long long int integer);
char	*ft_itoa_long(long long int integer);

/* new 15/01 */

char	*add_precision(char *integer, unsigned int precision);
char	*add_width(char *integer, unsigned int width, char *flag, unsigned int precision);
char	*add_flag(char *integer, char flag);
char	*add_flag_plus(char *integer);
char	*cpy_integer_with_sign(char *integer);
char	*ft_strnew(unsigned int size);
char 	*add_width_less(char *integer, unsigned int width);
char	*add_flag_space(char *integer);
char	*add_precision_string(char *s, int precision);
char	*add_width_string(char *s, int width, char *flag);

/* new 17/01 */
void	convert_wchar(va_list arg);
#endif
