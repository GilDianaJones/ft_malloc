/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:46:50 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:48:03 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (char *)malloc(size * sizeof(char))))
		return (NULL);
	ft_bzero(ret, size);
	return ((void *)ret);
}
