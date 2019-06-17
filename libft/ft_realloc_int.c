/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:38:22 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:52:33 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_realloc_int(int **tab, const int int_size, const int buffer)
{
	int		i;
	int		*tmp;

	i = 0;
	if (!(tmp = (int *)malloc((int_size + buffer + 1) * sizeof(int))))
		return ;
	while (i < int_size)
	{
		tmp[i] = (*tab)[i];
		i++;
	}
	free((*tab));
	(*tab) = (int *)malloc((buffer + int_size + 1) * sizeof(int));
	i = 0;
	while (i < int_size)
	{
		(*tab)[i] = tmp[i];
		i++;
	}
	free(tmp);
}
