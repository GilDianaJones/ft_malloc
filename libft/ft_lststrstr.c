/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:44:12 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:47:56 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list		*ft_lststrstr(t_list **begin, char *str)
{
	t_list *tmp;

	tmp = *begin;
	while (tmp)
	{
		if (tmp->content && !ft_strcmp(tmp->content + 1 +
			ft_strichr_last(tmp->content, '-'), str))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
