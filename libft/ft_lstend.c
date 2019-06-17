/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:25:06 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:47:19 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list		*ft_lstend(t_list **begin)
{
	t_list *tmp;

	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
