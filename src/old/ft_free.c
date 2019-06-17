/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 10:59:44 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/01 18:16:01 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			erase_block(t_block *prev, t_block *first)
{
	t_block		*block;

	block = g_blk;
	if (!prev)
		g_blk = g_blk->next;
	else
	{
		prev->next = g_blk->next;
		g_blk = first;
	}
	munmap((void *)block, block->type);
}

void			erase_elem(void *ptr)
{
	t_alloc		*lst;

	lst = g_blk->lst;
	if (ptr == (void *)lst + sizeof(*lst))
	{
		if (lst->size % 16)
			g_blk->size -= lst->size + 16 - lst->size % 16 + sizeof(*lst);
		else
			g_blk->size -= lst->size + sizeof(*lst);
		g_blk->lst = g_blk->lst->next;
		return ;
	}
	while (lst->next)
	{
		if (ptr == (void *)lst->next + sizeof(*lst->next))
		{
			if (lst->next->size % 16)
				g_blk->size -= lst->next->size + 16 - lst->next->size % 16 + sizeof(*lst->next);
			else
				g_blk->size -= lst->next->size + sizeof(*lst->next);
			lst->next = lst->next->next;
			break ;
		}
		lst = lst->next;
	}
}

void			free(void *ptr)
{
	t_block		*first;
//	t_block		*prev;

	pthread_mutex_lock(&g_mut);
	ft_lprintf("\nfree used\nptr : %p\n", ptr);
	if (!ptr || (g_blk && (ptr < (void *)g_blk->lst)))
	{
		pthread_mutex_unlock(&g_mut);
		return ;
	}
	first = g_blk;
//	prev = NULL;
	while (g_blk)
	{
		ft_lprintf("g_blk : %p\ng_blk max allocated : %p\ng_blk->next : %p\n", g_blk, (void *)g_blk + g_blk->size, (void *)g_blk->next);
		if ((ptr > (void *)g_blk) && (ptr < ((void *)g_blk + g_blk->size)))
		{
			ft_lprintf("I'm here\n");
			erase_elem(ptr);
//			if (!g_blk->lst && (g_blk->type != SMALL && g_blk->type != TINY))
//			{
//				erase_block(prev, first);
//				break ;
//			}
			g_blk = first;
			break ;
		}
//		prev = g_blk;
		g_blk = g_blk->next;
	}
	g_blk = first;
	pthread_mutex_unlock(&g_mut);
}
