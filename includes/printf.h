/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:44:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/28 05:26:08 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_infos
{
	char	*flag;
	int		width;
	int		prec;
	char	*modif;
	char	conv;
}				t_infos;

int		ft_printf(const char *rfmt, ...);
void	detect_infos(char *s, int c, t_infos *infos);
void	display_infos(t_infos *stt);
int		define_convert(va_list arg, t_infos *infos);

/* infos */

char	*search_flag(char *s);
char	*search_modif(char *s);
char	search_conv(char *s);
int		search_width(char *s);
int		search_prec(char *s);

int		is_flag(char c);
int		is_conv(char c);
int		is_modif(char c);

/* convert */

int		convert_int(va_list arg, t_infos *infos);
int		convert_string(va_list arg, t_infos *infos);
int		convert_pointer(va_list arg, t_infos *infos);

/* utils */

static int	hexaValue(int n);
char	*baseHexa(unsigned long int n);
char	*add0xAddr(char *s);

/* funcs */

char	*ft_itoa_long(long long int n);
char	*ft_itoa(int n);
int		ft_atoi(char *s);
char	ft_putchar(char c);
int		ft_strlen(char *s);

#endif
