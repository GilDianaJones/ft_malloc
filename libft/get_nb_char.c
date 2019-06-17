/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:59:52 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 13:40:54 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*get_nb_char(const char *str, int nb)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char *)malloc(nb * sizeof(char))))
		return (NULL);
	while (i < nb)
	{
		tmp[i] = str[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}
