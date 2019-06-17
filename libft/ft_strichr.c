/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:10:15 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:10:05 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_strichr(const char *s, char c)
{
	char	*src;
	int		i;

	src = (char *)s;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}
