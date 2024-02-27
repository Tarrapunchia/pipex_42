/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:51:28 by fzucconi          #+#    #+#             */
/*   Updated: 2024/02/27 16:47:29 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/pipex.h"

// int		cmd_len(char* str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != ' ')
// 		i++;
// 	return (i);
// }

// int		get_word_count(char *str)
// {
// 	int		count;
// 	int		i;
// 	char	sep;

// 	i = cmd_len(str);
// 	count = 1;
// 	while (str[i])
// 	{
// 		while (str[i] && str[i] == ' ')
// 			i++;
// 		if (str[i])
// 		{
// 			count++;
// 			while (str[i] && (str[i] != '\"' || str[i] != '\'') && str[i] != ' ')
// 				i++;
// 			if (str[i] && str[i] == '\"')
// 				sep = '\"';
// 			else if (str[i] && str[i] == '\'')
// 				sep = '\'';
// 			count++;
// 			while (str[i] && str[i] != sep)
// 				i++;
// 		}
// 	}
// 	return (count);
// }

// char	**parser (char *argv)
// {
// 	int len;
// 	char	**ret;
// 	if (!(ft_strchr(argv, '\'') || ft_strchr(argv, '\"')))
// 		return (ft_split(argv, ' '));
// 	len = get_word_count(argv);
// 	ret = (char **)malloc(sizeof(char *) * len + 1);
// 	if (!ret)
// 		error(3);
// 	return (NULL);
// }