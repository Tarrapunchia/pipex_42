/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:03:39 by fzucconi          #+#    #+#             */
/*   Updated: 2023/11/20 16:03:39 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line_bonus.h"
#include "../libft/libft.h"

char	*get_next_line(int fd)
{
	static t_list	*lists[MAX_FD];
	char			*ret;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	ret = NULL;
	ft_read_and_add(fd, &lists[fd]);
	if (!lists[fd])
		return (NULL);
	ft_fill_ret(lists[fd], &ret);
	ft_set_remainder(&lists[fd]);
	if ((ret && ret[0] == '\0') || !ret)
	{
		ft_free_all(lists[fd]);
		lists[fd] = NULL;
		if (ret)
			free (ret);
		ret = NULL;
	}
	return (ret);
}

void	ft_read_and_add(int fd, t_list **list)
{
	int		b_read;
	char	*buf;

	b_read = 1;
	while (!ft_check_nl(*list))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == 0)
			return ;
		b_read = (int)read(fd, buf, BUFFER_SIZE);
		if (b_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[b_read] = '\0';
		ft_stack_node(list, buf, b_read);
		free(buf);
	}
}

void	ft_stack_node(t_list **list, char *buf, int b_read)
{
	t_list	*node;
	int		i;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = 0;
	node->data = (char *)malloc(sizeof(char) * (b_read + 1));
	if (!(node->data))
		return ;
	i = 0;
	while (i < b_read)
	{
		node->data[i] = buf[i];
		i++;
	}
	node->data[i] = '\0';
	if (!*list)
	{
		*list = node;
		return ;
	}
	(ft_lst_get_last(*list))->next = node;
}

void	ft_fill_ret(t_list *list, char **ret)
{
	int	i;
	int	len;

	if (!list)
		return ;
	*ret = (char *)malloc(sizeof(char) * (ft_strlen_til_nl(list) + 1));
	if (!*ret)
		return ;
	len = 0;
	while (list)
	{
		i = 0;
		while (list->data[i])
		{
			if (list->data[i] == '\n')
			{
				(*ret)[len++] = list->data[i];
				break ;
			}
			(*ret)[len++] = list->data[i++];
		}
		list = list->next;
	}
	(*ret)[len] = '\0';
}

void	ft_set_remainder(t_list **list)
{
	t_list	*last;
	t_list	*remainder;
	int		i;
	int		j;

	remainder = (t_list *)malloc(sizeof(t_list));
	if (!list || !remainder)
		return ;
	remainder->next = 0;
	last = ft_lst_get_last(*list);
	i = 0;
	while (last->data[i] && last->data[i] != '\n')
		i++;
	if (last->data[i] && last->data[i] == '\n')
		i++;
	remainder->data = malloc(sizeof(char) * (ft_strlen(last->data) - i + 1));
	if (!remainder->data)
		return ;
	j = 0;
	while (last->data[i])
		remainder->data[j++] = last->data[i++];
	remainder->data[j] = '\0';
	ft_free_all(*list);
	*list = remainder;
}
