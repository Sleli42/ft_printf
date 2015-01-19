/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:50:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/19 17:45:17 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//#include "libft/libft.h"
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
//void	convert_hexa_l(va_list arg, t_infos *lst);
//void  	ft_print_hex(va_list arg);
//static char	*ft_hex_itoa(int n);
//char		get_hex_char(unsigned int tmp);
//static void	ft_hex_reverse(char *str);

/* new 19/01 */

char	*convert_int_hexa(int deci);
void	convert_hex(va_list arg, t_infos *lst);
char	add_letter_hexa(int n);
char	*hexa_convert(unsigned long int n, int spec, char flag);
static int	hexa_value(int n);
char	*add_u_precision(char *integer, int precision);
char	*add_u_width(char *integer, int width, char flag, int precision);
char	*offset_left(char *integer, int width);
char	*octal_convert(unsigned long int n, char flag);
char	*add_o_precision(char *s, int precision);
char	*add_o_width(char *s, int width, char flag, int precision);
char	*add_0(char *s);
char	*add_0x7fff_addr(char *s);

/* LIBFT */

int		ft_atoi(char const *s);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
char	*ft_strdup(char const *s1);
char	*ft_strnew(unsigned int size);
char	*ft_strcpy(char *dest, char const *src);
size_t	ft_strlen(char const *s);
int		ft_isdigit(int c);




#endif
