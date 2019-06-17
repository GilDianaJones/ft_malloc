/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:38:46 by gthomas           #+#    #+#             */
/*   Updated: 2018/12/20 16:03:59 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/malloc.h"
#include <stdio.h>
#include <stdlib.h>

void		ral(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	int		i;

	str = (char *)malloc(1500000);
	str = (char *)realloc(str, 3000000);
//	free(str);
	str = (char*)malloc(1500000);
	str2 = (char *)malloc(3000000);
	str = (char *)realloc(str, 2000000);
	str3 = (char *)malloc(1500000);
//	free(str3);
	str3 = (char *)malloc(1600000);
//	free(str3);
//	free(str2);
//	free(str);
	str = (char *)malloc(20);
	i = 0;
	while (i < 19)
	{
		str[i] = 'a' + i;
		++i;
	}
	str[i] = '\0';
	str = realloc(str, 1000000);
	str2 = (char *)malloc(10);
	i = 0;
	while (i < 9)
	{
		str2[i] = '0' + i;
		++i;
	}
	printf("adr str : %p\n", str);
	printf("adr ptr str : %p\n", &str);
	printf("adr str2 : %p\n", (void *)str2);
//	free(str);
//	free(str2);
}

int			main(void)
{
	ral();
	while(1);
	return (0);
/*	char	*str;
	char	*str2;
	char	*str3;
	int		i;

	str = (char *)malloc(15);
	show_alloc_mem();
	str = (char *)realloc(str, 30);
	show_alloc_mem();
	free(str);
	show_alloc_mem();
	str = (char*)malloc(15);
	str2 = (char *)malloc(30);
	show_alloc_mem();
	str = (char *)realloc(str, 20);
	show_alloc_mem();
	str3 = (char *)malloc(15);
	show_alloc_mem();
	free(str3);
	str3 = (char *)malloc(16);
	show_alloc_mem();
	free(str3);
	free(str2);
	free(str);
	show_alloc_mem();
	str = (char *)malloc(20);
	show_alloc_mem();
	i = 0;
	while (i < 19)
	{
		str[i] = 'a' + i;
		++i;
	}
	str[i] = '\0';
	ft_lprintf("%s\n", str);
	str = realloc(str, 10);
	str2 = (char *)malloc(10);
	show_alloc_mem();
	i = 0;
	while (i < 9)
	{
		str2[i] = '0' + i;
		++i;
	}
	ft_lprintf("%s\n", str);
	free(str);
	free(str2);
	show_alloc_mem();*/
}
