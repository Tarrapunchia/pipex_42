/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:37:29 by fzucconi          #+#    #+#             */
/*   Updated: 2024/02/27 18:19:02 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_all(t_pipex **pipex)
{
	int	i;

	i = 0;
	if (!pipex && !(*pipex))
		return ;
	while ((*pipex)->args && (*pipex)->args[i])
	{
		free((*pipex)->args[i]);
		(*pipex)->args[i] = NULL;
		i++;
	}
	if ((*pipex)->args)
		free((*pipex)->args);
	(*pipex)->args = NULL;
	free_all2(pipex);
}

void	free_all2(t_pipex **pipex)
{
	int	i = 0;

	i = 0;
	while ((*pipex)->paths && (*pipex)->paths[i])
	{
		free((*pipex)->paths[i]);
		(*pipex)->paths[i] = NULL;
		i++;
	}
	if ((*pipex)->paths)
	{
		free((*pipex)->paths);
		(*pipex)->paths = NULL;
	}
	if ((*pipex)->cmd)
	{
		free((*pipex)->cmd);
		(*pipex)->cmd = NULL;
	}
	if ((*pipex)->infile >= 0)
		close((*pipex)->infile);
	if ((*pipex)->outfile >= 0)
		close((*pipex)->outfile);
	free(*pipex);
}

void	error(int err_n, t_pipex **pipex)
{
	if (err_n == 1)
	{
		ft_putstr_fd("Too few args!", 2);
		free(*pipex);
		exit(1);
	}
	else if (err_n == 2)
		perror("args:");
	else if (err_n == 3)
		perror("cmd:");
	else if (err_n == 4)
		perror("execve:");
	else if (err_n == 5)
		perror("failed gnl in here_doc():");
	else if (err_n == 6)
		perror("piping:");
	else if (err_n == 7)
		perror("here_doc:");
	else if (err_n == 8)
		ft_putstr_fd("Too many args!", 2);
	else if (err_n == 9)
		perror("infile:");
	free_all(pipex);
	exit(1);
}

void	errors(int argc, t_pipex **pipex)
{
	if (argc < 5)
		error(1, pipex);
	if (argc > 5)
		error(8, pipex);
}

int	shorter(char **argv, int argc, t_pipex **pipex)
{
	int	i;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			error(1, pipex);
		i = 3;
		(*pipex)->outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0777);
		here_doc(argv[2], pipex);
	}
	else
	{
		i = 2;
		(*pipex)->infile = open(argv[1], O_RDONLY);
		if ((*pipex)->infile < 0)
			error(9, pipex);
		(*pipex)->outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2((*pipex)->infile, STDIN_FILENO);
	}
	return (i);
}
