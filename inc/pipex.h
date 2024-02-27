/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:37:39 by fzucconi          #+#    #+#             */
/*   Updated: 2024/02/27 18:17:47 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../inc/get_next_line_bonus.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**paths;
	char	**args;
	char	*cmd;
}	t_pipex;

/* ************************************************************************** */
/*							HERE_DOC.c										  */
/* ************************************************************************** */
void	here_doc(char *doc, t_pipex **pipex);

/* ************************************************************************** */
/*							 UTILS.c										  */
/* ************************************************************************** */
void	error(int err_n, t_pipex **pipex);
void	errors(int argc, t_pipex **pipex);
void	free_all(t_pipex **pipex);
void	free_all2(t_pipex **pipex);

/* ************************************************************************** */
/*						MAIN/MAIN_BONUS.c									  */
/* ************************************************************************** */
char	**split_paths(char **envp, t_pipex **pipex);
char	*check_cmd(t_pipex **pipex);
void	ft_exe(char *argv, t_pipex **pipex, char **envp);
void	piping(char *argv, t_pipex **pipex, char **envp);
void	piping_last(char *argv, t_pipex **pipex, char **envp);
int		shorter(char **argv, int argc, t_pipex **pipex);
void	free_paths(char **paths);

#endif