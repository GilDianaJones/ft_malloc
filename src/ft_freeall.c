/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:39:48 by gthomas           #+#    #+#             */
/*   Updated: 2018/12/24 16:56:50 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			freeall(void)
{
	t_block		*tmp_blk;

	if (!g_blk)
		return ;
	while (g_blk)
	{
		tmp_blk = g_blk->next;
		munmap(g_blk, sizeof(*g_blk));
		g_blk = tmp_blk;
	}
}
