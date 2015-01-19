/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:13:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/19 17:54:24 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list	arg;
	int		i;
	int		len;
	char	*cpy;
	t_infos	new;

	i = 0;
	cpy = ft_strdup(rfmt);
	va_start(arg, rfmt);
	while (cpy[i])
	{
		if (cpy[i] == '%' && cpy[i + 1] == '%')
		{
			ft_putchar('%');
			i = i + 2;
		}
		if (cpy[i] == '%')
		{
			detect_infos(cpy, i, &new);
		//	affiche_detect(&new);
			define_convert(&new, arg);
			while (cpy[i] != new.type)
				i++;
		}
		else
			ft_putchar(cpy[i]);
		i++;
	}
	va_end(arg);
}

int		main(void)
{
	long long int		i;
	long long int		j;
	int					test;
	char	*s;
	void	*addr;
	wchar_t c = L'暖'; 

	j = 42424;
	i = 214221;
	test = 4242;
	s = "baba au whum";
	addr = (char *)"poneeyyy";

	printf("\t\t-->[TEST %%o]<--\n\n");
	printf("[printf]test:\t |%o|\n", i);
	ft_printf("[ft_printf]test: |%o|\n\n", i);
	printf("[printf]test:\t |%ho|\n", i);
	ft_printf("[ft_printf]test: |%ho|\n\n", i);
	printf("[printf]test:\t |%#o|\n", i);
	ft_printf("[ft_printf]test: |%#o|\n\n", i);
	printf("[printf]test:\t |%#15o|\n", i);
	ft_printf("[ft_printf]test: |%#15o|\n\n", i);
	printf("[printf]test:\t |%#15.24o|\n", i);
	ft_printf("[ft_printf]test: |%#15.24o|\n\n", i);
	printf("[printf]test:\t |%.10o|\n", i);
	ft_printf("[ft_printf]test: |%.10o|\n\n", i);
	printf("[printf]test:\t |%#.10o|\n", i);
	ft_printf("[ft_printf]test: |%#.10o|\n\n", i);
	printf("[printf]test:\t |%20o|\n", i);
	ft_printf("[ft_printf]test: |%20o|\n\n", i);
	printf("[printf]test:\t |%20.12o|\n", i);
	ft_printf("[ft_printf]test: |%20.12o|\n\n", i);
	printf("[printf]test:\t |%-15o|\n", i);
	ft_printf("[ft_printf]test: |%-15o|\n\n", i);
	printf("[printf]test:\t |%-15.9o|\n", i);
	ft_printf("[ft_printf]test: |%-15.9o|\n\n", i);
	printf("\t\t-->[TEST %%x]<--\n\n");
	printf("[printf]test:\t |%x|\n", i);
	ft_printf("[ft_printf]test: |%x|\n\n", i);
	printf("[printf]test:\t |%X|\n", i);
	ft_printf("[ft_printf]test: |%X|\n\n", i);
	printf("[printf]test:\t |%#X|\n", i);
	ft_printf("[ft_printf]test: |%#X|\n\n", i);
	printf("[printf]test:\t |%#x|\n", i);
	ft_printf("[ft_printf]test: |%#x|\n\n", i);
	printf("[printf]test:\t |%hx|\n", i);
	ft_printf("[ft_printf]test: |%hx|\n", i);
	printf("[printf]test:\t |%d|\n", i);
	ft_printf("[ft_printf]test: |%d|\n\n", i);
	printf("[printf]test:\t |%x|\n", i);
	ft_printf("[ft_printf]test: |%x|\n\n", i);
	printf("[printf]test:\t |%X|\n", i);
	ft_printf("[ft_printf]test: |%X|\n\n", i);
	printf("[printf]test:\t |%#X|\n", i);
	ft_printf("[ft_printf]test: |%#X|\n\n", i);
	printf("[printf]test:\t |%#x|\n", i);
	ft_printf("[ft_printf]test: |%#x|\n\n", i);
	printf("[printf]test:\t |%hx|\n", i);
	ft_printf("[ft_printf]test: |%hx|\n\n", i);
	printf("\t\t-->[TEST %%u]<--\n\n");
	printf("[printf]test:\t |%u|\n", i);
	ft_printf("[ft_printf]test: |%u|\n\n", i);
	printf("[printf]test:\t |%20u|\n", i);
	ft_printf("[ft_printf]test: |%20u|\n\n", i);
	printf("[printf]test:\t |%.10u|\n", i);
	ft_printf("[ft_printf]test: |%.10u|\n\n", i);
	printf("[printf]test:\t |%20.10u|\n", i);
	ft_printf("[ft_printf]test: |%20.10u|\n\n", i);
	printf("[printf]test:\t |%#u|\n", i);
	ft_printf("[ft_printf]test: |%#u|\n\n", i);
	printf("[printf]test:\t |%#20u|\n", i);
	ft_printf("[ft_printf]test: |%#20u|\n\n", i);
	printf("[printf]test:\t |%#.12u|\n", i);
	ft_printf("[ft_printf]test: |%#.12u|\n\n", i);
	printf("[printf]test:\t |%#22.12u|\n", i);
	ft_printf("[ft_printf]test: |%#22.12u|\n\n", i);
	printf("[printf]test:\t |%020.10u|\n", i);
	ft_printf("[ft_printf]test: |%020.10u|\n\n", i);
	printf("[printf]test:\t |%020u|\n", i);
	ft_printf("[ft_printf]test: |%020u|\n\n", i);
	printf("[printf]test:\t |%-20u|\n", i);
	ft_printf("[ft_printf]test: |%-20u|\n\n", i);
	printf("[printf]test:\t |%-20.8u|\n", i);
	ft_printf("[ft_printf]test: |%-20.8u|\n\n", i);
	printf("\t\t-->[TEST %%s]<--\n\n");
	printf("[printf]test:\t |%s|\n", s);
	ft_printf("[ft_printf]test: |%s|\n\n", s);
	printf("[printf]test:\t |%42.42s|\n", s);
	ft_printf("[ft_printf]test: |%42.42s|\n\n", s);
	printf("[printf]test:\t |%021s|\n", s);
	ft_printf("[ft_printf]test: |%021s|\n\n", s);
	printf("[printf]test:\t |%-.4s|\n", s);
	ft_printf("[ft_printf]test: |%-.4s|\n\n", s);
	printf("[printf]test:\t |%-20s|\n", s);
	ft_printf("[ft_printf]test: |%-20s|\n\n", s);
	printf("[printf]test:\t |%-20.4s|\n", s);
	ft_printf("[ft_printf]test: |%-20.4s|\n\n", s);
	printf("[printf]test:\t |%-.4s|\n", s);
	ft_printf("[ft_printf]test: |%-.4s|\n\n", s);
	printf("\t\t-->[TEST %%d]<--\n\n");
	printf("[printf]test:\t |% .17d|\n", i);
	ft_printf("[ft_printf]test: |% .17d|\n\n", i);
	printf("[printf]test:\t |% 10.10d|\n", i);
	ft_printf("[ft_printf]test: |% 10.10d|\n\n", i);
	printf("[printf]test:\t |%hd|\n", i);
	ft_printf("[ft_printf]test: |%hd|\n\n", i);
	printf("[printf]test:\t |%+hd|\n", i);
	ft_printf("[ft_printf]test: |%+hd|\n\n", i);
	printf("[printf]test:\t |%-10hd|\n", i);
	ft_printf("[ft_printf]test: |%-10hd|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);
	printf("[printf]test:\t |%0.42d|\n", i);
	ft_printf("[ft_printf]test: |%0.42d|\n\n", i);
	printf("[printf]test:\t |%+.10ld|\n", i);
	ft_printf("[ft_printf]test: |%+.10ld|\n\n", i);
	printf("[printf]test:\t |%-10ld|\n", i);
	ft_printf("[ft_printf]test: |%-10ld|\n\n", i);
	printf("[printf]test:\t |%010.7d|\n", i);
	ft_printf("[ft_printf]test: |%010.7d|\n\n", i);
	printf("[printf]test:\t |%0.12hd|\n", i);
	ft_printf("[ft_printf]test: |%0.12hd|\n\n", i);
	printf("[printf]test:\t |%+10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%+10.12hd|\n\n", i);
	printf("[printf]test:\t |%-4.8hd|\n", i);
	ft_printf("[ft_printf]test: |%-4.8hd|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);
	printf("[printf]test:\t |%-10d|\n", i);
	ft_printf("[ft_printf]test: |%-10d|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);
	printf("\t\t-->[TEST %%p]<--\n\n");
	printf("[printf]test:\t |%p|\n", &test);
	ft_printf("[ft_printf]test: |%p|\n\n", &test);
	printf("[printf]test:\t |%p|\n", &s);
	ft_printf("[ft_printf]test: |%p|\n\n", &s);
	printf("[printf]test:\t |%p|\n", &addr);
	ft_printf("[ft_printf]test: |%p|\n\n", &addr);
	printf("\t\t-->[OTHER TEST]<--\n\n");
	printf("[printf]test:\t |%%|\n");
	ft_printf("[ft_printf]test: |%%|\n\n");
	printf("[printf]test:\t |%%poney|\n");
	ft_printf("[ft_printf]test: |%%poney|\n\n");
	return (0);
}
