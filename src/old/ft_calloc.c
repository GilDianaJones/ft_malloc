/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:55:44 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/01 18:16:25 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			*calloc(size_t nmemb, size_t size)
{
	void		*tmp;


	ft_lprintf("\ncalloc used\n");
	if ((ssize_t)nmemb <= 0 || (ssize_t)size <= 0)
		return (NULL);
	if ((tmp = (void *)malloc(nmemb * size)))
		ft_bzero(tmp, nmemb * size);
	return (tmp);
}
