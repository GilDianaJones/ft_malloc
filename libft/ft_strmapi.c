/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:19:14 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:12:20 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	i = 0;
	if (!s)
	{
		if (!(new = (char *)malloc((i + 1) * sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(new = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (NULL);
		while (s[i])
		{
			new[i] = (*f)(i, s[i]);
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}
