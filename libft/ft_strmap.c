/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:13:01 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:12:12 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		if (!(new = (char *)malloc((i + 1) * sizeof(char))))
			return (NULL);
		else
		{
			i = 0;
			while (s[i])
			{
				new[i] = (*f)(s[i]);
				i++;
			}
			new[i] = '\0';
		}
		return (new);
	}
	return (NULL);
}
