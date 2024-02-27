/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:04:45 by fzucconi          #+#    #+#             */
/*   Updated: 2023/11/20 16:04:45 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line_bonus.h"

int	ft_check_nl(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == 0)
		return (0);
	current = ft_lst_get_last(stash);
	i = 0;
	while (current->data[i])
	{
		if (current->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

size_t	ft_strlen_til_nl(t_list *list)
{
	int		i;
	size_t	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->data[i])
		{
			if (list->data[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_free_all(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->data);
		next = current->next;
		free(current);
		current = next;
	}
}
