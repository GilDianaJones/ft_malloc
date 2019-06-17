/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:28:53 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:46:47 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstaddend(t_list **lst, t_list *add)
{
	t_list *temp;

	if (*lst)
	{
		temp = *(lst);
		while (temp && temp->next)
		{
			temp = temp->next;
		}
		temp->next = add;
	}
	else
		*lst = add;
}
