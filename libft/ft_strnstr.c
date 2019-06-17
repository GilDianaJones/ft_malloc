/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:07:20 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:13:03 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)s1);
	if (ft_strlen(str2) > ft_strlen((char *)s1))
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		if (ft_strncmp((str1 + i), str2, ft_strlen(str2)) == 0)
		{
			if (ft_strlen(str2) == 1 && i <= n)
				return ((char *)(s1 + i));
			if (i + ft_strlen(str2) - 1 > n)
				return (NULL);
			else
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
