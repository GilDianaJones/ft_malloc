/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:00:05 by gthomas           #+#    #+#             */
/*   Updated: 2019/01/07 15:19:25 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <pthread.h>
# include <errno.h>

# define TINY	(size_t)(10 * getpagesize())
# define SMALL	(size_t)(1000 * getpagesize())
# define BLOCK	(sizeof(t_block) + sizeof(t_alloc))
# define ALLOC	(sizeof(t_block) + 100 * sizeof(t_alloc))

typedef struct			s_alloc
{
	size_t				size;
	struct s_alloc		*next;
}						t_alloc;

typedef struct			s_block
{
	size_t				type;
	size_t				size;
	t_alloc				*lst;
	struct s_block		*next;

}						t_block;

extern t_block			*g_blk;
extern pthread_mutex_t	g_mut;

void					*malloc(size_t size);
void					free(void *ptr);
void					show_alloc_mem(void);
void					*realloc(void *ptr, size_t size);
void					freeall(void);
void					*calloc(size_t nmemb, size_t size);
void					*reallocf(void *ptr, size_t size);
void					*valloc(size_t size);

#endif
