/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 11:54:55 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/01 18:57:25 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_block			*g_blk = NULL;
pthread_mutex_t	g_mut = PTHREAD_MUTEX_INITIALIZER;

void			*new_alloc(size_t size, t_alloc *new, void *next)
{
	if (!new)
	{
		ft_lprintf("I should not be here either\n");
		g_blk->lst = (void *)g_blk + sizeof(*g_blk);
		g_blk->lst->size = size;
		g_blk->lst->next = next;
		g_blk->size += size + sizeof(*g_blk->lst);
		return ((void *)g_blk->lst + sizeof(*g_blk->lst));
	}
	ft_lprintf("g_blk lst : %p\ng_blk : %p\n", g_blk->lst, (void *)g_blk + sizeof(*g_blk));
	if ((void *)g_blk->lst > ((void *)g_blk + sizeof(*g_blk) + sizeof(*g_blk->lst)))
	{
		ft_lprintf("I should not be here\n");
		if ((size + sizeof(*g_blk->lst)) <= ((void *)g_blk->lst -
					(void *)g_blk - sizeof(*g_blk)))
			g_blk->lst = new;
	}
	else
	{
		if (!new->next)
			ft_lprintf("I'm here\n");
		ft_lprintf("new : %p\nnew->next : %p\nnew->size : %d\n", new, new->next, new->size);
		if (new->size % 16)
			new->next = new + sizeof(t_alloc) + new->size + 16 - new->size % 16;
		else
			new->next = new + sizeof(t_alloc) + new->size;// + 16 - new->size % 16;
		ft_lprintf("new next : %p\n", new->next);
		new = new->next;
	}
	new->size = size;
	new->next = next;
	if (size % 16)
		g_blk->size += size + 16 - (size % 16) + sizeof(*new);
	else
		g_blk->size += size + sizeof(*new);
	ft_lprintf("g_blk adr max : %p\ng_blk size : %d\n", (void *)g_blk + g_blk->type, g_blk->size);
	return ((void *)new + sizeof(*new));
}

void			*fill_list(size_t size, t_block *first)
{
	t_alloc		*new;

	new = g_blk->lst;
	while (new)
	{
		if ((void *)g_blk->lst > ((void *)g_blk + sizeof(*g_blk)))
			if ((size + (16 - size % 16) + sizeof(*g_blk->lst)) <=
					((void *)g_blk->lst - (void *)g_blk - sizeof(*g_blk)))
			{
				ft_lprintf("Tell me i'm not here\n");
				return (new_alloc(size, (void *)g_blk + sizeof(*g_blk), new));
			}
		if (!new->next)
			break ;
		else if ((void *)new->next > ((void *)new + sizeof(*new) +
					new->size + (16 - new->size % 16)))
			if (size + (16 - size % 16) < ((new->next - new) - sizeof(*new) -
						new->size - (16 - new->size % 16)))
			{
				ft_lprintf("add new alloc\n");
				return (new_alloc(size, new, new->next));
			}
		new = new->next;
	}
	ft_lprintf("adr last lst : %p\n", (void *)new + sizeof(*new));
	new = new_alloc(size, (void *)new, NULL);
	g_blk = first;
	return (new);
}

t_block			*create_new_block(size_t size, size_t msize)
{
	t_block		*new_blk;

	new_blk = mmap(NULL, msize, PROT_WRITE | PROT_READ,
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (!new_blk)
	{
		errno = ENOMEM;
		return (NULL);
	}
	new_blk->type = msize;
	if (size % 16)
		new_blk->size = (size + 16 - size % 16 + sizeof(*new_blk) + sizeof(*new_blk->lst));
	else
		new_blk->size = (size + sizeof(*new_blk) + sizeof(*new_blk->lst));
	new_blk->next = NULL;
	new_blk->lst = (void *)new_blk + sizeof(*new_blk);// + 16 - (long int)new_blk % 16;
	new_blk->lst->size = size;
	new_blk->lst->next = NULL;
	return (new_blk);
}

void			*new_block(size_t size, size_t msize, t_block *first, void *new)
{
	if (!new && !first)
	{
		ft_lprintf("!new !first\n");
		g_blk = create_new_block(size, msize);
		ft_lprintf("new g_blk : %p\n", g_blk);
		new = (void *)g_blk->lst + sizeof(*g_blk->lst);
	}
	else if (!new)
	{
		ft_lprintf("!new\n");
		g_blk->next = create_new_block(size, msize);
		ft_lprintf("new g_blk next : %p\n", g_blk->next);
		new = (void *)g_blk->next->lst + sizeof(*g_blk->next->lst);
		g_blk = first;
	}
	pthread_mutex_unlock(&g_mut);
	ft_lprintf("align new alloc : %d\nnew : %p\n", (long int)new % 16, new);
	return (new);
}

void			*malloc(size_t size)
{
	size_t		msize;
	void		*new;
	t_block		*first;


	if ((ssize_t)size <= 0)
		return (NULL);
	pthread_mutex_lock(&g_mut);
	ft_lprintf("\nmalloc used\nsize asked : %d\ng_blk : %p\n", size, g_blk);
	first = g_blk;
	new = NULL;
	msize = size + BLOCK;
	if (size * 100 <= TINY + ALLOC)
		msize = TINY;
	else if (size * 100 <= SMALL + ALLOC)
		msize = SMALL;
	while (g_blk)
	{
		ft_lprintf("g_blk : %p\n", g_blk);
		if (msize == g_blk->type && msize <= ((SMALL + ALLOC) / 100) &&
				(size + 16 - size % 16) < (g_blk->type - (g_blk->size + sizeof(*g_blk->lst))))
			new = fill_list(size, first);
		if (!g_blk->next || new)
			break ;
		g_blk = g_blk->next;
	}
	return (new_block(size, msize, first, new));
}
