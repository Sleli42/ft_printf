/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:44:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 04:24:34 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "colors.h"

typedef struct	s_infos
{
	char	*flag;
	int		width;
	int		prec;
	char	*modif;
	char	conv;
}			t_infos;

typedef struct	s_chkStr
{
	int		return_val;
	int		tmp;
}			t_chkStr;


/* libft */
int		ft_atoi(char const *s);
long long int	ft_atoi_long(char *s);
char	*ft_itoa(int n);
char	*ft_itoa_long(long long int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_long(unsigned long int n);
size_t	ft_strlen(char const *s);
char	*ft_strrev(char const *s);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_isdigit(int c);
int		ft_isalpha(int c);

/* printf.c */
int		ft_printf(const char *rfmt, ...);
int		checkString(char *s, va_list arg, t_infos *new, t_chkStr *chk);
void	noConv(char *s, int c, t_infos *infos, t_chkStr *chk);
int		noConvSpec(char *s, int c, t_chkStr *chk);
int		checkIfAnotherPercent(char *s, int c, t_chkStr *chk);

/* init.c */
t_chkStr	*initChkStr(t_chkStr *chk);
int		detect_infos(char *s, int c, t_infos *new);
int		define_convert(va_list arg, t_infos *infos);

/* search_infos.c */
char	*search_flag(char *s, int c);
char	*ft_help_flag(char *s, int i);
char	skipSpaces(char *s, int c);
char	search_conv(char *s, int c);

/* search_infos2.c */
int		search_width(char *s, int c);
int		search_prec(char *s, int c);
char	*search_modif(char *s, int c, char conv);
char	*searchChar(char *s, int c);

/* is_infos.c */
int		is_flag(char c);
int		is_conv(char c);
int		is_modif(char c);

/* convert */
int		convert_int(va_list arg, t_infos *infos);
int		convert_string(va_list arg, t_infos *infos);
int		convert_pointer(va_list arg, t_infos *infos);
int		convert_unsigned(va_list arg, t_infos *infos);
int		convert_char(va_list arg, t_infos *infos);

/* convert */
int		convert_long_int(va_list arg, t_infos *infos);
int		convert_octal(va_list arg, t_infos *infos);
int		convert_hexa(va_list arg, t_infos *infos);
int		convert_wchar(va_list arg, t_infos *infos);
int		convert_wchar_string(va_list arg, t_infos *infos);

/* base.c */
char	*baseBinary(int n);
int		baseDecimal(char *bin);
char	*baseHexa(unsigned long long int n, int spec);
char	*baseOctal(unsigned long long int n);

/* add_width.c */
char	*addWidth(char *s, int width, char *flag);
char	*addWidth0x(char *s, int width, char *flag);
int		addWidthWchar(int width, char *flag);

/* add_prec.c */
char	*addPrec(char *s, int prec);
char	*addPrecString(char *s, int prec);
char	*addPrecAddr(char *s, int prec);
char	*addPrecHexa(char *s, int prec);

/* add_flag.c */
char	*addSharpOctal(char *s);
char	*addSharpHexa(char *s, int spec);
char	*addPlus(char *s);
char	*addSpace(char *s);
char	*addFlagInteger(char *flag, char *s);

/* add_flag2.c */
char	*addFlagInteger2(char *flag, char *s);

/* wchar.c */
int		printWchar(int value);
int		maskUnicode(char *bin, int lenMask);
int		splitBinary(char *bin, int lenMask);
int		displayWchar(char **tab, int nb);
int		definePrecWchar(int prec);

/* utils */
int		hexaValue(int n);
int		hexaValueMaj(int n);
char	*add0xAddr(char *s);
int		nextPercent(char *s, int c);
int		defineLenString(char *s, int c, t_infos *infos);

#endif
