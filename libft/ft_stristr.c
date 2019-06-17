/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:46:41 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:10:58 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int					ft_stristr(const char *str1, const char *str2)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (ft_strlen((char *)str2) == 0)
		return (0);
	else if (ft_strlen((char *)str2) > ft_strlen((char *)str1))
		return (-1);
	while (str1[i] != '\0')
	{
		while (str1[i + j] == str2[j] && str1[i + j] != '\0' && str2[j] != '\0')
			j++;
		if (str2[j] == '\0' && j > 0)
			return (i);
		i++;
		j = 0;
	}
	return (-1);
}
