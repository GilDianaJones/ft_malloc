/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:07:18 by gthomas           #+#    #+#             */
/*   Updated: 2018/12/25 17:15:56 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			show_block(t_alloc *alloc, int *size_tot)
{
	while (alloc)
	{
		ft_lprintf("       -       |  %p  |  %p  |       -       | %d o\n",
				(void *)alloc + sizeof(*alloc), (void *)alloc +
				sizeof(*alloc) + alloc->size, alloc->size);
		*size_tot += alloc->size;
		alloc = alloc->next;
	}
}

void			show_header(t_block *block, int *size_tot)
{
	int			padding;

	padding = (15 - (ft_intlen(block->type) + 2));
	ft_lprintf("  %p  |  %p  |", block, (void *)block + block->type);
	wnbchar(' ', padding / 2);
	ft_lprintf("%d o", block->type);
	wnbchar(' ', (padding / 2) + (padding % 2));
	ft_lprintf("| %d o\n", block->size);
	show_block(block->lst, size_tot);
	wnbcharnl('-', 80);
}

void			print_template(void)
{
	wnbcharnl('=', 80);
	ft_lprintf(" TYPE OF BLOCK |     START     |      END      |");
	ft_lprintf("    MAP SIZE   |   ALLOC SIZE\n");
	wnbcharnl('=', 80);
}

void			show_alloc_mem(void)
{
	t_block		*temp;
	int			size_tot;

	pthread_mutex_lock(&g_mut);
	temp = g_blk;
	size_tot = 0;
	if (temp)
	{
		print_template();
		while (temp)
		{
			if (temp->type == TINY)
				ft_lprintf("      TINY     |");
			else if (temp->type == SMALL)
				ft_lprintf("     SMALL     |");
			else
				ft_lprintf("     LARGE     |");
			show_header(temp, &size_tot);
			temp = temp->next;
		}
		ft_lprintf("Total allocated : %d octets\n\n", size_tot);
	}
	pthread_mutex_unlock(&g_mut);
}
