/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:54:36 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:15:25 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*get_str_before(char *out, const char *str, char c)
{
	int i;
	int cnt;

	i = 0;
	if (out)
		ft_strclr(out);
	cnt = ft_strichr(str, c);
	while (i < cnt)
	{
		out[i] = str[i];
		++i;
	}
	out[i] = '\0';
	return (out);
}
