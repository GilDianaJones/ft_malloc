/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:31:15 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:13:40 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	size_t	beg;

	if (s)
	{
		beg = (size_t)start;
		i = 0;
		if (!(new = (char *)malloc((len + 1) * sizeof(char))))
			return (NULL);
		else
		{
			while (s[start] && (size_t)start < (len + beg))
			{
				new[i] = s[start];
				i++;
				start++;
			}
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
