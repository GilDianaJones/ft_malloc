/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:05:48 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/07 15:43:09 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

//#include <stdio.h>

int		main(void)
{
	char *str;
	char *str2;
	char *str3;
	char *str4;
//	char *str5;
//	char *str6;
	int i;

	i = 0;
	ft_lprintf("TINY_size : %d octets\n", TINY);
	ft_lprintf("SMALL_size : %d octets\n", SMALL);
//	write(1, "aa\n",3);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	str = (char *)valloc(11);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "bb\n", 3);
	str2 = (char *)calloc(1, 11);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "cc\n", 3);
	str3 = (char *)malloc(175);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "dd\n", 3);
	str4 = (char *)malloc(175000);
	show_alloc_mem();
//	str5 = (char *)malloc(11);
//	str6 = (char *)malloc(11);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "ee\n", 3);
/*
	ft_lprintf("page size = %d\nstr = %p\nstr2 = %p\nstr3 = %p\nstr4 = %p\n", getpagesize(), str, str2, str3, str4);
	if (!str || !str2 || !str3 || !str4)
	{
		ft_lprintf("Erreur de malloc\n");
		return (-1);
	}
	while (i < 10)
	{

		str[i] = 'a' + i;
		str2[i] = '0' + i;
		str3[i] = '0' + i;
		str4[i] = 'A' + i;
//		str5[i] = 'm' + i;
//		str6[i] = 'M' + i;
//		printf("i = %d\tstr[%d] = %c\n", i, i, str[i]);
//		printf("i = %d\n", i);
		++i;
	}
	str[i] = '\0';
	str2[i] = '\0';
	str3[i] = '\0';
	str4[i] = '\0';
//	str5[i] = '\0';
//	str6[i] = '\0';
//	ft_strcpy(str, "abcdefghij");
	ft_lprintf("%s\n%s\n%s\n%s\n", str, str2, str3, str4);
	show_alloc_mem();
//	printf("alc->t = %p\n", g_alc.t);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	ft_lprintf("adr str2 : %p\n", (void *)str2);
	free(str2);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
	free(str4);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
	str2 = (char *)malloc(11);
//	ft_lprintf("adr of str2 : %p\n", (void *)str2);
//	str2 = "0123456789\0";
//	ft_lprintf("adr of str2 : %p\n", (void *)str2);
	show_alloc_mem();
	free(str);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
//	ft_lprintf("adr of str2 : %p\n", (void *)str2);
	free(str3);
//	ft_lprintf("free str3\n");
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
//	ft_lprintf("adr of str2 : %p\n", (void *)str2);
	free(str2);
//	ft_lprintf("free str2\n");
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();

//	free(str5);
//	ft_lprintf("%s\n", str5);
//	while(1);
	i = 0;
//	write(1, "aa\n",3);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	str = (char *)malloc(4000000);
//	show_alloc_mem();
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "bb\n", 3);
	str2 = (char *)malloc(11);
//	show_alloc_mem();
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "cc\n", 3);
	str3 = (char *)malloc(175);
//	show_alloc_mem();
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "dd\n", 3);
	str4 = (char *)malloc(175000);
//	show_alloc_mem();
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "ee\n", 3);

	ft_lprintf("page size = %d\nstr = %p\nstr2 = %p\nstr3 = %p\nstr4 = %p\n", getpagesize(), str, str2, str3, str4);
	if (!str || !str2 || !str3 || !str4)
	{
		ft_lprintf("Erreur de malloc\n");
		return (-1);
	}
	while (i < 10)
	{

		str[i] = 'a' + i;
		str2[i] = '0' + i;
		str3[i] = '0' + i;
		str4[i] = 'A' + i;
//		printf("i = %d\tstr[%d] = %c\n", i, i, str[i]);
//		printf("i = %d\n", i);
		++i;
	}
	str[i] = '\0';
	str2[i] = '\0';
	str3[i] = '\0';
	str4[i] = '\0';
//	ft_strcpy(str, "abcdefghij");
	ft_lprintf("%s\n%s\n%s\n%s\n", str, str2, str3, str4);
	show_alloc_mem();
//	printf("alc->t = %p\n", g_alc.t);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	ft_lprintf("free str\n");
	free(str);
	ft_lprintf("str has been freed\n");
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
//	ft_lprintf("%s\n%s\n%s\n",str2,str3,str4);
	free(str2);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
//	ft_lprintf("%s\n%s\n%s\n",str,str3,str4);
	free(str3);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
//	ft_lprintf("%s\n",str4);
//	while(1);
	free(str4);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();

	i = 0;
//	write(1, "aa\n",3);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	str = (char *)malloc(40000000);
//	show_alloc_mem();
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "bb\n", 3);
	str2 = (char *)malloc(11);
//	show_alloc_mem();
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "cc\n", 3);
	str3 = (char *)malloc(175);
//	show_alloc_mem();
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "dd\n", 3);
	str4 = (char *)malloc(175000);
//	show_alloc_mem();
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
//	write(1, "ee\n", 3);

	ft_lprintf("page size = %d\nstr = %p\nstr2 = %p\nstr3 = %p\nstr4 = %p\n", getpagesize(), str, str2, str3, str4);
	if (!str || !str2 || !str3 || !str4)
	{
		ft_lprintf("Erreur de malloc\n");
		return (-1);
	}
	while (i < 10)
	{

		str[i] = 'a' + i;
		str2[i] = '0' + i;
		str3[i] = '0' + i;
		str4[i] = 'A' + i;
//		printf("i = %d\tstr[%d] = %c\n", i, i, str[i]);
//		printf("i = %d\n", i);
		++i;
	}
	str[i] = '\0';
	str2[i] = '\0';
	str3[i] = '\0';
	str4[i] = '\0';
//	ft_strcpy(str, "abcdefghij");
	ft_lprintf("%s\n%s\n%s\n%s\n", str, str2, str3, str4);
	show_alloc_mem();
//	printf("alc->t = %p\n", g_alc.t);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	free(str2);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
//	ft_lprintf("%s\n%s\n%s\n",str2,str3,str4);
	free(str3);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
//	ft_lprintf("%s\n%s\n",str3,str4);
	free(str);
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();
//	ft_lprintf("%s\n",str4);
//	while(1);
	ft_lprintf("free str4\n");
	free(str4);
	ft_lprintf("str4 has been freed\n");
//	ft_lprintf("adr g_blk main : %p\n", g_blk);
	show_alloc_mem();

*/
//	while (1);
//	exit(EXIT_SUCCESS);
	freeall();
	return (0);
}
