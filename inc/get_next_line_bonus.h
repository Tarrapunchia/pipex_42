/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:03:00 by fzucconi          #+#    #+#             */
/*   Updated: 2024/01/23 16:42:12 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* ************************************************************************** */
/*          		         GENERAL DEFS	                                  */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MAX_FD 1024

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}	t_list;

/* ************************************************************************** */
/*          		         get_next_line.c                                  */
/* ************************************************************************** */

char	*get_next_line(int fd);
void	ft_read_and_add(int fd, t_list **list);
void	ft_stack_node(t_list **list, char *buf, int b_read);
void	ft_fill_ret(t_list *list, char **ret);
void	ft_set_remainder(t_list **list);

/* ************************************************************************** */
/*	      		 	         get_next_line_utils.c                            */
/* ************************************************************************** */

size_t	ft_strlen_til_nl(t_list *list);
void	ft_free_all(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
int		ft_check_nl(t_list *stash);

#endif
