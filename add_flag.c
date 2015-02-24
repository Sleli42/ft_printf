/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:41:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/24 05:01:28 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*addSharpOctal(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);

}

char	*addSharpHexa(char *s, int spec)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 3);
	i = 0;
	ret[i++] = '0';
	if (spec == 1)
		ret[i++] = 'X';
	else
		ret[i++] = 'x';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*addPlus(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = '+';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*addSpace(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = ' ';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*addFlagInteger(char *flag, char *s)
{
	if ((flag[0] == ' ' && flag[1] == '+')
			|| (flag[0] == '+' && flag[1] == ' '))
	{
		s = addPlus(s);
	//	printf("s= |%s|!!\n", s);
	}
	if (flag[0] == '+' && s[0] != '-' && flag[1] == '\0')
		s = addPlus(s);
	if (flag[0] == ' ' && flag[1] != '+' && flag[1] != '0' && s[0] != '-')
		s = addSpace(s);
	if (flag[0] == ' ' && flag[1] == '0')
	{
		s = addSharpOctal(s);
		s = addSpace(s);
	}
	if (flag[0] == '+' && flag[1] == '0')
	{
		if (s[0] == '0')
			s = addSharpOctal(s);
		s = addPlus(s);
	}
	//else
	//	s = addFlagInteger2(flag, s);
	return (s);
}
