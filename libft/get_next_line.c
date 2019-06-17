/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <gthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:11:51 by gthomas           #+#    #+#             */
/*   Updated: 2018/12/13 20:54:07 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

static void			ft_lstinit(t_list **gnl, t_list **tmp, size_t fd)
{
	if ((*tmp) && (*tmp)->content_size != fd)
	{
		(*tmp)->next = ft_lstnew(NULL, -1);
		(*tmp) = (*tmp)->next;
		(*tmp)->content_size = fd;
	}
	if (!(*tmp))
	{
		(*tmp) = ft_lstnew(NULL, -1);
		(*tmp)->content_size = fd;
		(*gnl) = (*tmp);
	}
}

static int			getback_rest(t_list *gnl, char **line, size_t fd)
{
	while (gnl && gnl->content_size != fd && gnl->next)
		gnl = gnl->next;
	if (gnl && gnl->content_size == fd && gnl->content)
	{
		free(*line);
		if (!((*line) = (char *)malloc((ft_strlen(gnl->content) + 1)
			* sizeof(char))))
			return (-1);
		ft_strcpy((*line), gnl->content);
		free(gnl->content);
		gnl->content = NULL;
	}
	return (1);
}

static int			read_fd(size_t fd, char **line)
{
	int				ret;
	int				nb_n;
	char			buf[BUFF_SIZE + 1];

	nb_n = (ft_strichr((*line), '\n') >= 0 ? 1 : 0);
	while (!nb_n)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		ft_frealloc(line, BUFF_SIZE);
		ft_strconcat(line, buf);
		if (ft_strichr((*line), '\n') >= 0 || ret != BUFF_SIZE)
			nb_n++;
		if (!ret && !(*line)[0])
			return (0);
	}
	return (1);
}

static int			save_rest(t_list **gnl, char **line, size_t fd)
{
	int				i;
	int				len;
	t_list			*tmp;

	tmp = (*gnl);
	len = ft_strlen(*line);
	if ((i = ft_strichr((*line), '\n')) == -1)
		i = len + 1;
	if (len > i - 1)
	{
		while (tmp && tmp->content_size != fd && tmp->next)
			tmp = tmp->next;
		ft_lstinit(gnl, &tmp, fd);
		if (tmp && tmp->content_size == fd)
		{
			if (!(tmp->content = (char *)malloc((len - i) * sizeof(char))))
				return (-1);
			ft_strcpy(tmp->content, (*line) + (i + 1));
			(*line)[i] = '\0';
		}
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*gnl = NULL;
	int				res;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!((*line) = (char *)malloc(sizeof(char))))
		return (-1);
	(*line)[0] = '\0';
	if ((res = getback_rest(gnl, line, (size_t)fd)) != 1)
		return (res);
	if ((res = read_fd((size_t)fd, line)) != 1)
		return (res);
	if ((res = save_rest(&gnl, line, (size_t)fd)) != 1)
		return (res);
	return (1);
}
