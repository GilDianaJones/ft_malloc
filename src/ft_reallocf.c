/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:10:43 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/07 16:18:37 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

/*
static void				*check_for_no_new(t_block *b, void *new, void *ptr, size_t size)
{

	t_alloc			*a;

	while (b)
	{
		if ((ptr < ((void *)b + b->size)) && (size <= b->size + sizeof(*b)))
		{
			a = b->lst;
			while (a)
			{
				if (ptr == (void *)a + sizeof(*a))
				{
					if (!a->next || a->next >= a + sizeof(*a) + size)
					{
						//b->size -= a->size - size + 16 - size % 16;
						a->size = size;
						//new = ptr;
						return (ptr);
					}
					break ;
				}
				a = a->next;
			}
			break ;
		}
		b = b->next;
	}
	return (new);
}

static int					find_alloc_size(void *ptr)
{
	int				ret;
	t_block			*b;
	t_alloc			*a;

	ret = -1;
	b = g_blk;
	while (b)
	{
		if (ptr >= (void *)b->lst)
		{
			a = b->lst;
			while (a)
			{
				if (ptr == (void *)a + sizeof(*a))
				{
					ret = (int)a->size;
					return (ret);
				}
				a = a->next;
			}
		}
		b = b->next;
	}
	return (ret);
}

static void				*cannot_allocate(void *ptr, size_t size)
{
	void			*tmp;

	tmp = (void *)malloc(size);
	if (!ptr)
	{
		errno = ENOMEM;
		free(ptr);
		return (NULL);
	}
	return (tmp);
 } */

void				*reallocf(void *ptr, size_t size)
{
	void			*new;

	ft_lprintf("reallocf is used\n");
	new = realloc(ptr, size);
	if (!new && ptr)
		free(ptr);
	return (new);
/*	int				cpysize;

	ft_lprintf("reallocf is used\n");
	if (!ptr || (ptr && ((ssize_t)size <= 0)))
		return (cannot_allocate(ptr, size));
	new = NULL;
	pthread_mutex_lock(&g_mut);
	if (ptr)
	{
		new = check_for_no_new(g_blk, NULL, ptr, size);
		pthread_mutex_unlock(&g_mut);
	}
	if (!new)
	{
		if ((cpysize = find_alloc_size(ptr)) == -1)
		{
			errno = ENOMEM;
			return (NULL);
		}
		pthread_mutex_unlock(&g_mut);
		new = (void *)malloc(size);
		pthread_mutex_lock(&g_mut);
		if (ptr)
		{
			ft_memcpy(new, ptr, cpysize);
			pthread_mutex_unlock(&g_mut);
			free(ptr);
		}
	}
	return (new); */
}
