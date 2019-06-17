/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:36:56 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:48:31 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *src1;
	unsigned char *src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (src1 < (unsigned char *)s1 + n && src2 < (unsigned char *)s2 + n)
	{
		if (*src1 > *src2 || *src1 < *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
	}
	return (0);
}
