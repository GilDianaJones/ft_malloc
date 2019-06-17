/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:38:04 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:13:17 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((unsigned char)s[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)(s + i));
	while ((unsigned char)s[j] != c && s[j] != '\0')
		j++;
	if (j == i)
		return (NULL);
	while ((unsigned char)s[i] != c && i != 0)
		i--;
	return ((char *)(s + i));
}
