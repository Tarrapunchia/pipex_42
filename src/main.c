/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:29:40 by fzucconi          #+#    #+#             */
/*   Updated: 2024/02/27 17:55:44 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**split_paths(char **envp, t_pipex **pipex)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	error(3, pipex);
	return (NULL);
}

char	*check_cmd(t_pipex **pipex)
{
	char	*tmp;
	char	*buf;
	int		i;

	i = 0;
	buf = ft_strjoin("/", (*pipex)->args[0]);
	while ((*pipex)->paths[i])
	{
		tmp = ft_strjoin((*pipex)->paths[i], buf);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		free(buf);
		tmp = NULL;
		buf = ft_strjoin("/", (*pipex)->args[0]);
		i++;
	}
	free(tmp);
	free(buf);
	error(2, pipex);
	return (NULL);
}

void	ft_exe(char *argv, t_pipex **pipex, char **envp)
{
	(*pipex)->args = ft_split(argv, ' ');
	if (!(*pipex)->args)
		error(2, pipex);
	(*pipex)->cmd = check_cmd(pipex);
	if (!(*pipex)->cmd)
		error(3, pipex);
	if (execve((*pipex)->cmd, (*pipex)->args, envp) == -1)
		error(4, pipex);
}
t_pipex	*pipex_init(void)
{
	t_pipex	*out;

	out = (t_pipex *)malloc(sizeof(t_pipex));
	if (!out)
		exit(0);
	out->infile = -1;
	out->outfile = -2;
	out->paths = NULL;
	out->args = NULL;
	out->cmd = NULL;

	return (out);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pipex	*pipex;

	pipex = pipex_init();
	errors(argc, pipex);
	pipex->paths = split_paths(envp, &pipex);
	if (!pipex->paths)
		error(1, &pipex);
	i = shorter(argv, argc, &pipex);
	while (i <= (argc - 2))
	{
		if (i == (argc - 2))
			piping_last(argv[i], &pipex, envp);
		else
			piping(argv[i], &pipex, envp);
		i++;
	}
	free_all(&pipex);
	return (0);
}
