/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:31:40 by fzucconi          #+#    #+#             */
/*   Updated: 2024/02/27 16:43:59 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	control_put(char *ret, char *doc, int fd[2], t_pipex **pipex)
{
	if (!ret)
		error(5, pipex);
	if (ft_strncmp(ret, doc, ft_strlen(doc)) == 0)
	{
		free(ret);
		exit(0);
	}
	ft_putstr_fd(ret, fd[1]);
	free(ret);
}

void	here_doc(char *doc, t_pipex **pipex)
{
	char	*ret;
	int		fd[2];
	pid_t	pid;

	if ((pipe(fd)) == -1)
		error(7, pipex);
	pid = fork();
	if (pid == -1)
		error(7, pipex);
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			ret = get_next_line(STDIN_FILENO);
			control_put(ret, doc, fd, pipex);
		}
	}
	else if (pid != 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}
