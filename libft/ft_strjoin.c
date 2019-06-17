/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:38:37 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:11:48 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 && s2)
	{
		j = ft_strlen(s2);
		if (!(new = (char *)malloc((ft_strlen(s1) + j + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			new[i + j] = s2[j];
			j++;
		}
		new[i + j] = '\0';
		return (new);
	}
	return (NULL);
}
