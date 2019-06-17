/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:29:55 by gthomas           #+#    #+#             */
/*   Updated: 2018/12/24 16:03:20 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

typedef struct		s_store
{
	int				stock;
	pthread_t		thread_store;
	pthread_t		thread_clients [5];
}					t_store;
 
static t_store store =
{
	.stock = 20,
};

static void		*test_store(void *i)
{
	char		*str;

//	ft_lprintf("Creation du thread store avec premier malloc\n");
	str = (char *)malloc(15 + (size_t)i);
	show_alloc_mem();
	str = (char *)realloc(str, 20 + (size_t)i);
	show_alloc_mem();
//	str[0] = 'o';
//	str[1] = '\0';
//	ft_lprintf("%s\n", str);
	free(str);
//	show_alloc_mem();
	return ((void *)str);
}

static void		*test_client(void *i)
{
	char		*str;

//	ft_lprintf("Creation du %deme thread clients avec %deme malloc\n", i, i+2);
	str = (char *)malloc(15 + (size_t)i);
	show_alloc_mem();
	str = (char *)realloc(str, 20 + (size_t)i);
	show_alloc_mem();
//	str[0] = 'o';
//	str[1] = '\0';
//	ft_lprintf("%s\n", str);
	free(str);
//	show_alloc_mem();
	return ((void *)str);
}

int				main(void)
{
	char		*str;
	char		*str2;
	char		*str3;
	int			th;
	size_t			i;

	i = 0;
	ft_lprintf("Begin\n");
	th = pthread_create(&store.thread_store, NULL, test_store, (void *)i);
	if (th)
	{
		ft_lprintf("error pthread create\n");
		return (0);
	}
	while (i < 5)
	{
		th = pthread_create(&store.thread_clients [i], NULL, test_client, (void *)i);
		if (th)
		{
			ft_lprintf("error pthread create\n");
			return (0);
		}
		++i;
	}
	i = 0;
	while (i < 5)
	{
		pthread_join(store.thread_clients [i], NULL);
		i++;
	}
	pthread_join(store.thread_store, NULL);
	ft_lprintf("ici tout est free\n");
	show_alloc_mem();
	return (0);
}
