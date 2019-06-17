/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stritabstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:30:32 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:11:22 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_stritabstr(char **tab, char *str)
{
	int i;

	i = 0;
	while (tab[i] && ft_strcmp(tab[i], str))
		++i;
	return (i);
}
