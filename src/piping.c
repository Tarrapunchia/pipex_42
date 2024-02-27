/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:14:29 by fzucconi          #+#    #+#             */
/*   Updated: 2024/02/27 16:47:16 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	piping(char *argv, t_pipex **pipex, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(6, pipex);
	pid = fork();
	if (pid == -1)
		error(6, pipex);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exe(argv, pipex, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	piping_last(char *argv, t_pipex **pipex, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(6, pipex);
	pid = fork();
	if (pid == -1)
		error(6, pipex);
	if (pid == 0)
	{
		close(fd[0]);
		dup2((*pipex)->outfile, STDOUT_FILENO);
		ft_exe(argv, pipex, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}
