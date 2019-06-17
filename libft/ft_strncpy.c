/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:34:32 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:12:40 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] && i < n)
	{
		*dest = src[i];
		dest++;
		i++;
	}
	if (i < n)
	{
		while (i < n)
		{
			*dest = 0;
			dest++;
			i++;
		}
	}
	return (dest - n);
}
