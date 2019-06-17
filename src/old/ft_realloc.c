/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:00:47 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/01 18:57:28 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			*check_for_no_new(t_block *b, void *new, void *ptr, size_t size)
{
	t_alloc		*a;

	while (b)
	{
		if ((ptr < ((void *)b + b->size)) && (size <= b->size + sizeof(*b)))
		{
			ft_lprintf("block found\n");
			a = b->lst;
			while (a)
			{
				if (ptr == (void *)a + sizeof(*a))
				{
					ft_lprintf("alloc found\n");
					if (!a->next || a->next >= a + sizeof(*a) + size)
					{
						ft_lprintf("no need to malloc\nalloc size : %d\nnext alloc : %p\n", a->size, a->next);
		//				b->size -= a->size - size + 16 - size % 16;
						a->size = size;
				//		new = ptr;
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

int				find_alloc_size(void *ptr)
{
	int			ret;
	t_block		*b;
	t_alloc		*a;

	ret = -1;
	b = g_blk;
	while (b)
	{
		if (ptr >= (void *)b->lst)
		{
			ft_lprintf("block found\n");
			a = b->lst;
			while (a)
			{
				if (ptr == (void *)a + sizeof(*a))
				{
					ft_lprintf("alloc found\n");
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

void			*cannot_allocate(void *ptr, size_t size)
{
	if (!ptr)
		return ((void *)malloc(size));
	if (ptr && ((ssize_t)size <= 0))
	{
		errno = ENOMEM;
		free(ptr);
		return (NULL);
	}
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	void		*new;
	int			cpysize;

	ft_lprintf("\nrealloc used\nptr : %p\nsize : %d\n", ptr, size);
	if (!ptr || (ptr && ((ssize_t)size <= 0)))
		return (cannot_allocate(ptr, size));
	new = NULL;
	pthread_mutex_lock(&g_mut);
	if (ptr)
	{
		new = check_for_no_new(g_blk, NULL, ptr, size);
		ft_lprintf("I'm out without new malloc\n");
	}
	if (!new)
	{
		ft_lprintf("need to malloc a new one\n");
		if ((cpysize = find_alloc_size(ptr)) == -1)
		{
			ft_lprintf("ERROR : exact alloc not found\n");
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
	ft_lprintf("new : %p\n", new);
	return (new);
}
