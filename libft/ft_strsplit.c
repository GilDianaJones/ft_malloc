/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:54:46 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 13:40:16 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	cnt_line(char *s, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	if (s[0] == c)
	{
		while (s[i] == c)
			++i;
	}
	while (s[i])
	{
		if (s[i] == c)
		{
			++cnt;
			while (s[i] == c && s[i] != '\0')
				++i;
		}
		else
			++i;
	}
	return (cnt);
}

static char	**alloc_str(char *s, char c, char **new, int i)
{
	int nb;
	int j;

	nb = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
		{
			++nb;
			++i;
		}
		if (nb && (s[i] == c || s[i] == '\0'))
		{
			if (!(new[j] = (char *)malloc(nb + 1)))
				return (NULL);
			while (s[i] == c && s[i] != '\0')
				++i;
			nb = 0;
			++j;
		}
	}
	return (new);
}

static void	fill_str(char *s, char c, int i, char **new)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
		{
			new[j][k] = s[i];
			++i;
			++k;
		}
		if (k && (s[i] == c || s[i] == '\0'))
		{
			while (s[i] == c && s[i] != '\0')
				++i;
			new[j][k] = '\0';
			++j;
			k = 0;
		}
	}
	new[j] = NULL;
}

char		**ft_strsplit(char *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	if (s && ft_strlen(s) > 0)
	{
		if (!(new = (char **)malloc((cnt_line(s, c) + 1) * sizeof(char *))))
			return (NULL);
		new = alloc_str(s, c, new, 0);
		fill_str(s, c, 0, new);
		return (new);
	}
	return (NULL);
}
