/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 08:59:43 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:50:13 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*src;
	size_t	i;

	src = (char *)s;
	i = 0;
	while (i < n)
	{
		src[i] = c;
		i++;
	}
	return ((void *)src);
}
