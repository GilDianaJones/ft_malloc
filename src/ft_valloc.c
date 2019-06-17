/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:07:28 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/07 15:41:00 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

/*
#ifndef G_MALLOC_INIT
# define G_MALLOC_INIT
t_block				*g_blk = NULL;
pthread_mutex_t		g_mut = PTHREAD_MUTEX_INITIALIZER;
#endif*/

static void				*new_alloc(size_t size, t_alloc *new, void *next)
{
	if (!new)
	{
		g_blk->lst = (void *)g_blk + sizeof(*g_blk) + ft_align(sizeof(*g_blk), getpagesize()) - sizeof(*g_blk->lst);
		g_blk->lst->size = size;
		g_blk->lst->next = next;
		g_blk->size += ft_align(size, 16) + sizeof(*g_blk->lst);
		return ((void *)g_blk->lst + sizeof(*g_blk->lst));
	}
	if ((void *)g_blk->lst > ((void *)g_blk + sizeof(*g_blk) + sizeof(*g_blk->lst)))
	{
		if ((size + sizeof(*g_blk->lst)) <= ((void *)g_blk->lst -
					(void *)g_blk - sizeof(*g_blk)))
			g_blk->lst = new;
	}
	else
	{
		new->next = (void *)new + sizeof(*new) + ft_align(new->size, 16);
		new = new->next;
	}
	new->size = size;
	new->next = next;
	g_blk->size += ft_align(size, 16) + sizeof(*new);
	return ((void *)new + ft_align(sizeof(*g_blk), getpagesize()));
}

static void				*fill_list(size_t size, t_block *first)
{
	t_alloc			*new;

	new = g_blk->lst;
	if ((void *)g_blk->lst > ((void *)g_blk + sizeof(*g_blk)))
		if (ft_align(size,getpagesize() ) + sizeof(*g_blk->lst) <=
				((void *)g_blk->lst - (void *)g_blk - sizeof(*g_blk)))
			return (new_alloc(size, (void *)g_blk + sizeof(*g_blk), new));
	while (new)
	{
		if (!new->next)
			break ;
		if (ft_align(size, getpagesize()) + sizeof(*new) <= (((void *)new->next - (void *)new) - sizeof(*new) - ft_align(new->size, 16)))
			return (new_alloc(size, new, new->next));
		new = new->next;
	}
	new = new_alloc(size, (void *)new, NULL);
	g_blk = first;
	return (new);
}

static t_block				*create_new_block(size_t size, size_t msize)
{
	t_block			*new_blk;

	new_blk = mmap(NULL, msize, PROT_WRITE | PROT_READ,
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (!new_blk)
	{
		errno = ENOMEM;
		return (NULL);
	}
	new_blk->type = msize;
	new_blk->size = ft_align(size, 16) + sizeof(*new_blk) + sizeof(*new_blk->lst);
	new_blk->next = NULL;
	new_blk->lst = (void *)new_blk + sizeof(*new_blk) + ft_align(sizeof(*new_blk), getpagesize()) - sizeof(*new_blk->lst);
	new_blk->lst->size = size;
	new_blk->lst->next = NULL;
	return (new_blk);
}

static void				*new_block(size_t size, size_t msize, t_block *first, void *new)
{
	if (!new && !first)
	{
		g_blk = create_new_block(size, msize);
		new = (void *)g_blk->lst + sizeof(*g_blk->lst);
	}
	else if (!new)
	{
		g_blk->next = create_new_block(size, msize);
		new = (void *)g_blk->next->lst + sizeof(*g_blk->next->lst);
		g_blk = first;
	}
	pthread_mutex_unlock(&g_mut);
	return (new);
}

void				*valloc(size_t size)
{
	size_t			msize;
	void			*new;
	t_block			*first;

	ft_lprintf("valloc is used\n");
	if ((ssize_t)size <= 0)
		return (NULL);
	pthread_mutex_lock(&g_mut);
	first = g_blk;
	new = NULL;
	msize = size + BLOCK;
	if (size * 100 <= TINY + ALLOC)
		msize = TINY;
	else if (size * 100 <= SMALL + ALLOC)
		msize = SMALL;
	while (g_blk)
	{
		if (msize == g_blk->type && msize <= ((SMALL + ALLOC) / 100) &&
				(ft_align(size, getpagesize())) < (g_blk->type - (g_blk->size + sizeof(*g_blk->lst))))
			new = fill_list(size, first);
		if (!g_blk->next || new)
			break ;
		g_blk = g_blk->next;
	}
	return (new_block(size, msize, first, new));
}
