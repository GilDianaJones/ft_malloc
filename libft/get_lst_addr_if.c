/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst_addr_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:06:17 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:15:01 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*get_lst_addr_if(t_list **beg_lst, int (*f)(void *))
{
	t_list *tmp;

	tmp = *beg_lst;
	while (tmp->next && !(*f)(tmp->content))
	{
		tmp = tmp->next;
	}
	return (tmp);
}
