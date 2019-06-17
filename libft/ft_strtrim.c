/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:36:24 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 12:13:47 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_sp_before(char const *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] <= ' ' && i == 0)
		{
			while (s[j] <= ' ' && s[j] != '\0')
				j++;
		}
		i++;
	}
	return (j);
}

static int	ft_sp_after(char const *s)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		k = i;
		if (s[i + 1] == '\0' && s[i] <= ' ')
		{
			while (s[k] <= ' ' && k > 0)
				k--;
		}
		i++;
	}
	return (k);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		k;

	if (s)
	{
		k = ft_sp_after(s);
		if (k == 0)
		{
			if (!(new = (char *)malloc(sizeof(char))))
				return (NULL);
			new[0] = '\0';
			return (new);
		}
		if (!(new = (char *)malloc((k - ft_sp_before(s) + 2) * sizeof(char))))
			return (NULL);
		new[k - ft_sp_before(s) + 1] = '\0';
		while (s[k] && k >= ft_sp_before(s))
		{
			new[k - ft_sp_before(s)] = s[k];
			k--;
		}
		return (new);
	}
	return (NULL);
}
