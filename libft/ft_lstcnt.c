/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:08:26 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 13:42:07 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_lstcnt(t_list **begin)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (*begin)
	{
		tmp = *begin;
		while (tmp && tmp->content)
		{
			tmp = tmp->next;
			++i;
		}
	}
	return (i);
}
