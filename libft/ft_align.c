/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:27:29 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/02 14:32:16 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t			ft_align(size_t val, size_t base)
{
	size_t		ret;

	ret = val;
	if (val % base)
		ret += base - (val % base);
	return (ret);
}
