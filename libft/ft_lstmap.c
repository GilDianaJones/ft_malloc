/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:26 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:47:34 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;
	t_list *temp;
	t_list *lstnew;

	lstnew = NULL;
	begin = NULL;
	while (lst != NULL)
	{
		temp = f(lst);
		if (!(new = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		if (begin == NULL)
			begin = new;
		lst = lst->next;
		if (lstnew)
			lstnew->next = new;
		lstnew = new;
	}
	return (begin);
}
