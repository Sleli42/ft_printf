/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 06:12:34 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/19 07:04:38 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include	"printf.h"

static void	ft_hex_reverse(char *str)
{
	char	tmp;
	int		it;
	int 	len;

	len = ft_strlen(str);
	it = -1;
	while (++it < (len / 2))
	{
		tmp = str[it];
		str[it] = str[len - it - 1];
		str[len - it - 1] = tmp;
	}
	return ;
}

char		get_hex_char(unsigned int tmp)
{
	tmp = tmp % 16;
	if (tmp < 10)
		return (tmp + '0');
	return (tmp - 10 + 'a');
}
static char	*ft_hex_itoa(int n)
{
	int 			it;
	unsigned int 	tmp;
	char			*res_str;

	res_str = (char *)malloc(sizeof(char) * 12);
	it = -1;
	tmp = (unsigned int)n;
	while (++it < 12 && tmp)
	{
		res_str[it] = get_hex_char(tmp);
		tmp = tmp / 16;
	}
	res_str[it] = '\0';
	printf("res_str 1 : %s", res_str);
	ft_hex_reverse(res_str);
	printf("res_str 2 : %s", res_str);
	return (res_str);
}

void  		ft_print_hex(va_list arg)
{
	int		i;
	int		res;
	char	*to_print;

	res = 0;
	i = va_arg(arg, int);
	printf("%d\n", i);
	to_print = ft_hex_itoa(i);
	res = ft_strlen(to_print);
	write(1, to_print, res);
	printf("\n");
	//free(to_print);
	//eturn (res);
}*/