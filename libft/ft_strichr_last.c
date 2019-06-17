/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:08:46 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:10:34 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_strichr_last(const char *s, char c)
{
	char	*src;
	int		i;
	int		len;

	src = (char *)s;
	len = ft_strlen(src);
	i = 0;
	while (len >= 0)
	{
		if (src[len] == c)
			return (len);
		--len;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}
