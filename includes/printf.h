/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:44:37 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/13 17:53:48 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../libft/libft.h"
#include "colors.h"

typedef struct	s_infos
{
	char	*flag;
	int		width;
	int		prec;
	char	*modif;
	char	conv;
}				t_infos;

int		ft_printf(const char *rfmt, ...);
int		detect_infos(char *s, int c, t_infos *new);
void	display_infos(t_infos *stt);
int		define_convert(char *s, va_list arg, t_infos *infos);
int		initConv(char *s, int c);
int		checkString(char *s, va_list arg);

/* infos */

char	*search_flag(char *s, int c);
char	*search_modif(char *s, int c);
char	search_conv(char *s, int c);
int		search_width(char *s, int c);
int		search_prec(char *s, int c);

int		is_flag(char c);
int		is_conv(char c);
int		is_modif(char c);

/* convert */

int		convert_int(va_list arg, t_infos *infos);
int		convert_long_int(va_list arg, t_infos *infos);
int		convert_string(va_list arg, t_infos *infos);
int		convert_pointer(va_list arg, t_infos *infos);
int		convert_unsigned(va_list arg, t_infos *infos);
int		convert_octal(va_list arg, t_infos *infos);
int		convert_hexa(va_list arg, t_infos *infos);
int		convert_char(va_list arg, t_infos *infos);
int		convert_wchar(va_list arg, t_infos *infos);
int		convert_wchar_string(va_list arg, t_infos *infos);

/* utils */

int		hexaValue(int n);
int		hexaValueMaj(int n);
char	*baseHexa(unsigned long long int n, int spec);
char	*baseOctal(unsigned long long int n);
char	*add0xAddr(char *s);

/* utils 2 */

char	*addPrec(char *s, int prec);
char	*addPrecString(char *s, int prec);
char	*addWidth(char *s, int width, char *flag);
char	*addWidth0x(char *s, int width, char *flag);
char	*addSharpOctal(char *s);

/* utils 3 */

char	*addSharpHexa(char *s, int spec);
char	*addPlus(char *s);
char	*addSpace(char *s);
char	*addPrecAddr(char *s, int prec);
char	*addPrecHexa(char *s, int prec);

/* utils 4 */

char	*baseBinary(int n);
int		baseDecimal(char *bin);
int		maskUnicode(char *bin, int lenMask);
int		splitBinary(char *bin, int lenMask);
int		displayWchar(char **tab, int nb);

/* utils 5 */

int		printWchar(int value);
int		noConv(char *s, t_infos *infos);
int		nextPercent(char *s, int c);

#endif
